#ifndef ANALYSIS_ANALYSISALG_H
#define ANALYSIS_ANALYSISALG_H 1

#include "AthAnalysisBaseComps/AthAnalysisAlgorithm.h"

//Example ROOT Includes
#include "TTree.h"
#include "TH1D.h"
#include "TLorentzVector.h"
#include "xAODEventInfo/EventInfo.h"
#include <xAODTruth/TruthEventContainer.h>
#include <xAODTruth/TruthParticleContainer.h>
#include <xAODMuon/MuonContainer.h>
#include <xAODEgamma/ElectronContainer.h>
// #include <xAODJet/JetContainer.h>
// #include <xAODTracking/TrackParticleContainer.h>
// #include <xAODMissingET/MissingETContainer.h>
// #include <xAODCaloEvent/CaloClusterContainer.h>

class AnalysisAlg : public ::AthAnalysisAlgorithm
{
public:
  AnalysisAlg(const std::string &name, ISvcLocator *pSvcLocator);
  virtual ~AnalysisAlg();

  ///uncomment and implement methods as required

  //IS EXECUTED:
  virtual StatusCode initialize();     //once, before any input is loaded
  virtual StatusCode beginInputFile(); //start of each input file, only metadata loaded
  //virtual StatusCode  firstExecute();   //once, after first eventdata is loaded (not per file)
  virtual StatusCode execute(); //per event
  //virtual StatusCode  endInputFile();   //end of each input file
  //virtual StatusCode  metaDataStop();   //when outputMetaStore is populated by MetaDataTools
  virtual StatusCode finalize(); //once, after all events processed

  ///Other useful methods provided by base class are:
  ///evtStore()        : ServiceHandle to main event data storegate
  ///inputMetaStore()  : ServiceHandle to input metadata storegate
  ///outputMetaStore() : ServiceHandle to output metadata storegate
  ///histSvc()         : ServiceHandle to output ROOT service (writing TObjects)
  ///currentFile()     : TFile* to the currently open input file
  ///retrieveMetadata(...): See twiki.cern.ch/twiki/bin/view/AtlasProtected/AthAnalysisBase#ReadingMetaDataInCpp

private:
  unsigned int m_runNumber = 0;
  unsigned long long m_eventNumber = 0;
  int matchedMuon;
  int matchedElectron;
  std::vector<float> *pt_Chis = nullptr;
  std::vector<float> *eta_Chis = nullptr;
  std::vector<float> *phi_Chis = nullptr;
  std::vector<int> *m_matchedMuons = nullptr;
  std::vector<float> *pt_muons = nullptr;
  std::vector<float> *eta_muons = nullptr;
  std::vector<float> *phi_muons = nullptr;
  std::vector<int> *actual_muons =nullptr;
  std::vector<int> *m_matchedElectrons = nullptr;
  std::vector<float> *pt_electrons = nullptr;
  std::vector<float> *eta_electrons = nullptr;
  std::vector<float> *phi_electrons = nullptr;
  std::vector<int> *actual_electrons = nullptr;
  std::vector<float> *mu_Eloss = nullptr;

  std::vector<TLorentzVector> chis;
};

#endif //> !ANALYSIS_ANALYSISALG_H
