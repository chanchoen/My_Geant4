#include "OTDetectorConstruction.hh"
#include "G4RunManager.hh"


#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"



OTDetectorConstruction::OTDetectorConstruction()
: G4VUserDetectorConstruction()
{
}

OTDetectorConstruction::~OTDetectorConstruction()
{
}

G4VPhysicalVolume* OTDetectorConstruction::Construct()
{
  
  G4Box *gasDetector = new G4Box("Detector", 5*cm, 5*cm, 5*cm);

  G4NistManager* nist = G4NistManager::Instance();

  G4Material*methane = nist -> FindOrBuildMaterial("G4_METHANE");
  G4Material *Ar  = nist -> FindOrBuildMaterial("G4_Ar");
  
  G4Material *P10 = new G4Material("P10gas", 0.0015617*g/cm3, 2, kStateGas, 293.15*kelvin);
  
  P10 -> AddMaterial(Ar,0.9);
  P10 -> AddMaterial(methane,0.1);

  logicDetector = new G4LogicalVolume(gasDetector, P10, "Detector");
  
  G4PVPlacement* detector = new G4PVPlacement(0, G4ThreeVector(0,0,0), logicDetector, "Detector", 0, false, 0, true);



 
  return detector;
}
