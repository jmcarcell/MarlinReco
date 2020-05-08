#ifndef photonCorrectionProcessor_h
#define photonCorrectionProcessor_h 1
#include "marlin/Processor.h"

#include "photonCorrector.h"
#include "TFile.h"
#include "TH2F.h"

//using namespace marlin ;

class photonCorrectionProcessor : public marlin::Processor {
  
 public:
  
  virtual Processor*  newProcessor() { return new photonCorrectionProcessor ; }
  
  photonCorrectionProcessor() ;
  
  /** Called at the begin of the job before anything is read.
   * Use to initialize the processor, e.g. book histograms.
   */
  virtual void init() ;
  
  /** Called for every run.
   */
  virtual void processRunHeader( LCRunHeader* run ) ;
    
  /** Called for every event - the working horse.
   */
  virtual void processEvent( LCEvent * evt ) ; 

  virtual void check( LCEvent * evt ) ; 
  
  /** Called after data processing for clean up.
   */
  virtual void end() ;

  photonCorrectionProcessor(const photonCorrectionProcessor&) = delete;
  photonCorrectionProcessor& operator=(const photonCorrectionProcessor&) = delete;

 protected:

  photonCorrector* _photonCorrector{};

  bool _modifyPFOenergies{};
  bool _modifyPFOdirections{};

  bool _validationPlots{};
  float _nominalEnergy{};

  std::string _inputCollection{};

  float _barrelendcap_limit_costh{};
  float _assumed_boxsize{};
  float _assumed_endZ{};

  float _energyLin_const{};
  float _energyLin_logen{};

  float _phiBarrelCorr_pos_const{};
  float _phiBarrelCorr_pos_logen{};
  float _phiBarrelCorr_depth{};
  float _phiBarrelCorr_width1{};
  float _phiBarrelCorr_width2{};

  float _costhCorr_gaus1_norm_const{};
  float _costhCorr_gaus1_norm_logen{};
  float _costhCorr_gaus1_mean{};
  float _costhCorr_gaus1_sigm{};

  float _costhCorr_gaus2_norm_const{};
  float _costhCorr_gaus2_norm_logen{};
  float _costhCorr_gaus2_mean{};
  float _costhCorr_gaus2_sigm{};

  float _costhCorr_gaus3_norm{};
  float _costhCorr_gaus3_mean{};
  float _costhCorr_gaus3_sigm{};
  float _costhCorr_endcap_scale{};

  float _endcap_gaus1_norm{};
  float _endcap_gaus1_mean{};
  float _endcap_gaus1_sigm{};
  float _endcap_gaus2_norm{};
  float _endcap_gaus2_mean{};
  float _endcap_gaus2_sigm{};


  float _phiBias_barrel_p0_1  {};
  float _phiBias_barrel_p0_2  {};
  float _phiBias_barrel_p0_3  {};
  float _phiBias_barrel_p0_4  {};
  float _phiBias_barrel_p1_1  {};
  float _phiBias_barrel_p1_2  {};
  float _phiBias_barrel_p2_1  {};
  float _phiBias_barrel_p2_2  {};
  float _phiBias_barrel_p3_1  {};
  float _phiBias_barrel_p4_1  {};
  float _phiBias_barrel_p5_1  {};
  float _phiBias_barrel_p5_2  {};
  float _phiBias_barrel_p5_3  {};
  float _phiBias_barrel_p6_1  {};
  float _phiBias_barrel_p6_2  {};
  float _phiBias_barrel_p7_1  {};
  float _phiBias_barrel_p7_2  {};
  float _phiBias_barrel_p7_3  {};

  float _thetaBias_barrel_p0_1{};
  float _thetaBias_barrel_p0_2{};
  float _thetaBias_barrel_p1_1{};
  float _thetaBias_barrel_p1_2{};

  float _thetaBias_endcap_p0_1{};
  float _thetaBias_endcap_p0_2{};
  float _thetaBias_endcap_p1_1{};
  float _thetaBias_endcap_p1_2{};
  float _thetaBias_endcap_p2_1{};
  float _thetaBias_endcap_p2_2{};


};


#endif



