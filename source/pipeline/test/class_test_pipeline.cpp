

class test_pipeline :
    public testing::TestWithParam<const char*> {
		
		
  auto data_path = std::filesystem::path(TEST_DATA_DIR);
  
   
  // в помещении-большой

  auto irl1_img1  = cv::imread((data_path / "irl/1/irl1_img1.jpg").string());
  auto irl1_img2 = cv::imread((data_path / "irl/1/irl1_img2.jpg").string());
  auto irl1_img3 = cv::imread((data_path / "irl/1/irl1_img3.jpg").string());
  
  auto irl2_img1  = cv::imread((data_path / "irl/2/irl2_img1.jpg").string());
  auto irl2_img2 = cv::imread((data_path / "irl/2/irl2_img2.jpg").string());
  auto irl2_img3 = cv::imread((data_path / "irl/2/irl2_img3.jpg").string());
  
  // в помещении-средний

  auto irm1_img1  = cv::imread((data_path / "irm/1/irm1_img1.jpg").string());
  auto irm1_img2 = cv::imread((data_path / "irm/1/irm1_img2.jpg").string());
  auto irm1_img3 = cv::imread((data_path / "irm/1/irm1_img3.jpg").string());
  
  auto irm2_img1 = cv::imread((data_path / "irm/2/irm2_img1.jpg").string());
  auto irm2_img2 = cv::imread((data_path / "irm/2/irm2_img2.jpg").string());
  auto irm2_img3 = cv::imread((data_path / "irm/2/irm2_img3.jpg").string());
  
  auto irm3_img1 = cv::imread((data_path / "irm/3/irm3_img1.jpg").string());
  auto irm3_img2 = cv::imread((data_path / "irm/3/irm3_img2.jpg").string());
  auto irm3_img3 = cv::imread((data_path / "irm/3/irm3_img3.jpg").string());
  
  //в помещении-малый
  
  auto irs1_img1 = cv::imread((data_path / "irs/1/irs1_img1.jpg").string());
  auto irs1_img2 = cv::imread((data_path / "irs/1/irs1_img2.jpg").string());
  auto irs1_img3 = cv::imread((data_path / "irs/1/irs1_img3.jpg").string());
  
  auto irs2_img1 = cv::imread((data_path / "irs/2/irs2_img1.jpg").string());
  auto irs2_img2 = cv::imread((data_path / "irs/2/irs2_img2.jpg").string());
  auto irs2_img3 = cv::imread((data_path / "irs/2/irs2_img3.jpg").string());
  
  auto irs3_img1 = cv::imread((data_path / "irs/3/irs3_img1.jpg").string());
  auto irs3_img2 = cv::imread((data_path / "irs/3/irs3_img2.jpg").string());
  auto irs3_img3 = cv::imread((data_path / "irs/3/irs3_img3.jpg").string());
  
  auto irs4_img1 = cv::imread((data_path / "irs/4/irs4_img1.jpg").string());
  auto irs4_img2 = cv::imread((data_path / "irs/4/irs4_img2.jpg").string());
  auto irs4_img3 = cv::imread((data_path / "irs/4/irs4_img3.jpg").string());
  
  //здания-большой
  
  auto bl1_img1 = cv::imread((data_path / "bl/1/bl1_img1.jpg").string());
  auto bl1_img2 = cv::imread((data_path / "bl/1/bl1_img2.jpg").string());
  auto bl1_img3 = cv::imread((data_path / "bl/1/bl1_img3.jpg").string());
  
  auto bl2_img1 = cv::imread((data_path / "bl/2/bl2_img1.jpg").string());
  auto bl2_img2 = cv::imread((data_path / "bl/2/bl2_img2.jpg").string());
  auto bl2_img3 = cv::imread((data_path / "bl/2/bl2_img3.jpg").string());
  
  auto bl3_img1 = cv::imread((data_path / "bl/3/bl3_img1.jpg").string());
  auto bl3_img2 = cv::imread((data_path / "bl/3/bl3_img2.jpg").string());
  auto bl3_img3 = cv::imread((data_path / "bl/3/bl3_img3.jpg").string());
  
  auto bl4_img1 = cv::imread((data_path / "bl/4/bl4_img1.jpg").string());
  auto bl4_img2 = cv::imread((data_path / "bl/4/bl4_img2.jpg").string());
  auto bl4_img3 = cv::imread((data_path / "bl/4/bl4_img3.jpg").string());
  
  //здания-средний
  
  auto bm1_img1 = cv::imread((data_path / "bm/1/bm1_img1.jpg").string());
  auto bm1_img2 = cv::imread((data_path / "bm/1/bm1_img2.jpg").string());
  auto bm1_img3 = cv::imread((data_path / "bm/1/bm1_img3.jpg").string());
  
  auto bm2_img1 = cv::imread((data_path / "bm/2/bm2_img1.jpg").string());
  auto bm2_img2 = cv::imread((data_path / "bm/2/bm2_img2.jpg").string());
  auto bm2_img3 = cv::imread((data_path / "bm/2/bm2_img3.jpg").string());
  
  auto bm3_img1 = cv::imread((data_path / "bm/3/bm3_img1.jpg").string());
  auto bm3_img2 = cv::imread((data_path / "bm/3/bm3_img2.jpg").string());
  auto bm3_img3 = cv::imread((data_path / "bm/3/bm3_img3.jpg").string());
  
  auto bm4_img1 = cv::imread((data_path / "bm/4/bm4_img1.jpg").string());
  auto bm4_img2 = cv::imread((data_path / "bm/4/bm4_img2.jpg").string());
  auto bm4_img3 = cv::imread((data_path / "bm/4/bm4_img3.jpg").string());
  
  //здания-малый
  
  auto bs1_img1 = cv::imread((data_path / "bs/1/bs1_img1.jpg").string());
  auto bs1_img2 = cv::imread((data_path / "bs/1/bs1_img2.jpg").string());
  auto bs1_img3 = cv::imread((data_path / "bs/1/bs1_img3.jpg").string());
  
  auto bs2_img1 = cv::imread((data_path / "bs/2/bs2_img1.jpg").string());
  auto bs2_img2 = cv::imread((data_path / "bs/2/bs2_img2.jpg").string());
  auto bs2_img3 = cv::imread((data_path / "bs/2/bs2_img3.jpg").string());
  
  auto bs3_img1 = cv::imread((data_path / "bs/3/bs3_img1.jpg").string());
  auto bs3_img2 = cv::imread((data_path / "bs/3/bs3_img2.jpg").string());
  auto bs3_img3 = cv::imread((data_path / "bs/3/bs3_img3.jpg").string());
  
  auto bs4_img1 = cv::imread((data_path / "bs/4/bs4_img1.jpg").string());
  auto bs4_img2 = cv::imread((data_path / "bs/4/bs4_img2.jpg").string());
  auto bs4_img3 = cv::imread((data_path / "bs/4/bs4_img3.jpg").string());
  
  //природа-большой
  
  auto nl1_img1 = cv::imread((data_path / "nl/1/nl1_img1.jpg").string());
  auto nl1_img2 = cv::imread((data_path / "nl/1/nl1_img2.jpg").string());
  auto nl1_img3 = cv::imread((data_path / "nl/1/nl1_img3.jpg").string());
  
  auto nl2_img1 = cv::imread((data_path / "nl/2/nl2_img1.jpg").string());
  auto nl2_img2 = cv::imread((data_path / "nl/2/nl2_img2.jpg").string());
  auto nl2_img3 = cv::imread((data_path / "nl/2/nl2_img3.jpg").string());
  
  auto nl3_img1 = cv::imread((data_path / "nl/3/nl3_img1.jpg").string());
  auto nl3_img2 = cv::imread((data_path / "nl/3/nl3_img2.jpg").string());
  auto nl3_img3 = cv::imread((data_path / "nl/3/nl3_img3.jpg").string());
  
  auto nl4_img1 = cv::imread((data_path / "nl/4/nl4_img1.jpg").string());
  auto nl4_img2 = cv::imread((data_path / "nl/4/nl4_img2.jpg").string());
  auto nl4_img3 = cv::imread((data_path / "nl/4/nl4_img3.jpg").string());
  
  //природа-средний
  
  auto nm1_img1 = cv::imread((data_path / "nm/1/nm1_img1.jpg").string());
  auto nm1_img2 = cv::imread((data_path / "nm/1/nm1_img2.jpg").string());
  auto nm1_img3 = cv::imread((data_path / "nm/1/nm1_img3.jpg").string());
  
  auto nm2_img1 = cv::imread((data_path / "nm/2/nm2_img1.jpg").string());
  auto nm2_img2 = cv::imread((data_path / "nm/2/nm2_img2.jpg").string());
  auto nm2_img3 = cv::imread((data_path / "nm/2/nm2_img3.jpg").string());
  
  auto nm3_img1 = cv::imread((data_path / "nm/3/nm3_img1.jpg").string());
  auto nm3_img2 = cv::imread((data_path / "nm/3/nm3_img2.jpg").string());
  auto nm3_img3 = cv::imread((data_path / "nm/3/nm3_img3.jpg").string());
  
  auto nm4_img1 = cv::imread((data_path / "nm/4/nm4_img1.jpg").string());
  auto nm4_img2 = cv::imread((data_path / "nm/4/nm4_img2.jpg").string());
  auto nm4_img3 = cv::imread((data_path / "nm/4/nm4_img3.jpg").string());
  
  //природа-малый
  
  auto ns1_img1 = cv::imread((data_path / "ns/1/ns1_img1.jpg").string());
  auto ns1_img2 = cv::imread((data_path / "ns/1/ns1_img2.jpg").string());
  auto ns1_img3 = cv::imread((data_path / "ns/1/ns1_img3.jpg").string());
  
  auto ns2_img1 = cv::imread((data_path / "ns/2/ns2_img1.jpg").string());
  auto ns2_img2 = cv::imread((data_path / "ns/2/ns2_img2.jpg").string());
  auto ns2_img3 = cv::imread((data_path / "ns/2/ns2_img3.jpg").string());
  
  auto ns3_img1 = cv::imread((data_path / "ns/3/ns3_img1.jpg").string());
  auto ns3_img2 = cv::imread((data_path / "ns/3/ns3_img2.jpg").string());
  auto ns3_img3 = cv::imread((data_path / "ns/3/ns3_img3.jpg").string());
  
  auto ns4_img1 = cv::imread((data_path / "ns/4/ns4_img1.jpg").string());
  auto ns4_img2 = cv::imread((data_path / "ns/4/ns4_img2.jpg").string());
  auto ns4_img3 = cv::imread((data_path / "ns/4/ns4_img3.jpg").string());
  
  
  void SetUp() override { img1 = (*GetParam())(); }
  void SetUp() override { img2 = (*GetParam())(); }
  
  void TearDown() override {
	  
    delete img1;
    img1 = nullptr;
	
	delete img2;
    img2 = nullptr;
  }
  
  
};