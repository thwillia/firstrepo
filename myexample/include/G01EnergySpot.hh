//
// ********************************************************************
// * License and Disclaimer                                           *
// *                                                                  *
// * The  Geant4 software  is  copyright of the Copyright Holders  of *
// * the Geant4 Collaboration.  It is provided  under  the terms  and *
// * conditions of the Geant4 Software License,  included in the file *
// * LICENSE and available at  http://cern.ch/geant4/license .  These *
// * include a list of copyright holders.                             *
// *                                                                  *
// * Neither the authors of this software system, nor their employing *
// * institutes,nor the agencies providing financial support for this *
// * work  make  any representation or  warranty, express or implied, *
// * regarding  this  software system or assume any liability for its *
// * use.  Please see the license in the file  LICENSE  and URL above *
// * for the full disclaimer and the limitation of liability.         *
// *                                                                  *
// * This  code  implementation is the result of  the  scientific and *
// * technical work of the GEANT4 collaboration.                      *
// * By using,  copying,  modifying or  distributing the software (or *
// * any work based  on the software)  you  agree  to acknowledge its *
// * use  in  resulting  scientific  publications,  and indicate your *
// * acceptance of all terms of the Geant4 Software license.          *
// ********************************************************************
//
//
// $Id: G01EnergySpot.hh 70911 2013-06-07 11:05:37Z mverderi $
//
#ifndef G01EnergySpot_h
#define G01EnergySpot_h

#include "G4ThreeVector.hh"
class G4Colour;

class G01EnergySpot
{
public:
  G01EnergySpot();
  G01EnergySpot(const G4ThreeVector& point, G4double E);
  ~G01EnergySpot();

  inline void SetEnergy(const G4double& E) {fEnergy = E;}
  inline G4double GetEnergy() const {return fEnergy;}

  inline void SetPosition(const G4ThreeVector& point) {fPoint = point;}
  inline G4ThreeVector GetPosition() const {return fPoint;}

  G4int operator==(const G01EnergySpot& eSpot) const
  {
    return (fEnergy==eSpot.fEnergy && fPoint==eSpot.fPoint) ? 1 : 0;
  }

  // Draw:
  void Draw(G4Colour* color = 0);
  // Print:
  void Print();


private:
  G4double fEnergy;
  G4ThreeVector fPoint;
};

#endif
