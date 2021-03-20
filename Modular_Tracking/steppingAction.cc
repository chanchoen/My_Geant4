#include "OTSteppingAction.hh"
#include "OTEventAction.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4SystemOfUnits.hh"

#include "G4EventManager.hh"

OTSteppingAction::OTSteppingAction()
: G4UserSteppingAction()
{
}

OTSteppingAction::~OTSteppingAction()
{
}

void OTSteppingAction::UserSteppingAction(const G4Step* step)
{
  G4int muPDG = step -> GetTrack() -> GetDefinition() -> GetPDGEncoding();
  if (muPDG == 13){
    G4double length = step -> GetStepLength();

    G4AnalysisManager* analysisManager = G4AnalysisManager::Instance();

    analysisManager -> FillNtupleDColumn(2, 0, length);
    analysisManager -> AddNtupleRow(2);
  }
    
}
