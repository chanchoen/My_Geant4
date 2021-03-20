#ifndef OTDETECTORCONSTRUCTION_HH
#define OTDETECTORCONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

#include "G4SystemOfUnits.hh"

class G4VPhysicalVolume;
class G4PhysicsList;
class G4UserPhysicsList;


class G4LogicalVolume;

class OTDetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    OTDetectorConstruction();
    virtual ~OTDetectorConstruction();

    virtual G4VPhysicalVolume* Construct();
  
};


#endif
