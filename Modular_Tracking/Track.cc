#include "track.hh"
#include "OTEventAction.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"

#include "G4EventManager.hh"

track::track()
: G4UserTrackingAction()
{
}

track::~track()
{
}


void track::PreUserTrackingAction(const G4Track* t)
{
  G4int parentID = t -> GetParentID();
  G4double energy = t -> GetKineticEnergy();
  G4int pdg = t -> GetDefinition() -> GetPDGEncoding();


  G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();
  
  OTEventAction *eventAction = (OTEventAction *) G4EventManager::GetEventManager() -> GetUserEventAction();
  if (parentID == 1 && pdg == 11)
    {
      analysisManager -> FillNtupleDColumn(0, energy);
      analysisManager -> AddNtupleRow();
      eventAction -> GenerateElectron(parentID);
      
    }
}
