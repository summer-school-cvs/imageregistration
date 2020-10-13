#pragma once

#include <stitching/core/logging.h>

#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>

namespace stitching::core {

class Factory {
 public:
  template <typename T, typename... Args>
  using CreatorFun = std::function<std::shared_ptr<T>(Args...)>;
  using KeyType    = std::string;

  template <typename T, typename... Args>
  static void registrate(const KeyType &key, CreatorFun<T, const KeyType &, Args...> fun) {
    SPDLOG_LOGGER_INFO(getLogger("stitching.factory"), "Register {}", key);
    creatorsMap<T, const KeyType &, Args...>()[key] = std::move(fun);
  }

  template <typename T, typename... Args>
  static std::shared_ptr<T> create(const KeyType &key, Args... args) {
    auto &creator_map = creatorsMap<T, const std::string &, Args...>();
    if (auto iter = creator_map.find(key); iter != creator_map.end())
      return iter->second(key, std::forward<Args>(args)...);

    return {};
  }

 private:
  template <typename T, typename... Args>
  static auto &creatorsMap() {
    static std::map<KeyType, CreatorFun<T, Args...>> map;
    return map;
  }
};

struct FactoryHelper {
  template <typename T, typename... Args>
  FactoryHelper(const std::string &                                                    key,
                typename Factory::template CreatorFun<T, const std::string &, Args...> creator)
      : key_val(key) {
    Factory::registrate<T>(key, std::move(creator));
  }

  const std::string key_val;
};

}  // namespace stitching::core

#define REGISTER_TYPE(iface, name, creator)                                                        \
  std::string name##_##iface##_factory_helper_fun() {                                              \
    static stitching::core::FactoryHelper name##_##iface##_factory_helper(#name,                   \
                                                                          std::function(creator)); \
    return name##_##iface##_factory_helper.key_val;                                                \
  }                                                                                                \
  static const std::string iface##name##Key = name##_##iface##_factory_helper_fun()

#define DEFINE_TYPE(iface, name)                                  \
  std::string              name##_##iface##_factory_helper_fun(); \
  static const std::string iface##name##Key = name##_##iface##_factory_helper_fun()
