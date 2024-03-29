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
// $Id: G01PionShowerModel.hh 70911 2013-06-07 11:05:37Z mverderi $
//
// 
//----------------------------------------------
// Parameterisation for pi+/pi- producing hits.
//----------------------------------------------
#ifndef G01PionShowerModel_h
#define G01PionShowerModel_h 1

#include "G01EnergySpot.hh"

#include "G4VFastSimulationModel.hh"
#include "G4Step.hh"
#include "G4TouchableHandle.hh"
#include <vector>

class G01PionShowerModel : public G4VFastSimulationModel
{
public:
  //-------------------------
  // Constructor, destructor
  //-------------------------
  G01PionShowerModel (G4String, G4Region*);
  G01PionShowerModel (G4String);
  ~G01PionShowerModel ();

  //------------------------------
  // Virtual methods of the base
  // class to be coded by the user
  //------------------------------

  // -- IsApplicable
  virtual G4bool IsApplicable(const G4ParticleDefinition&);
  // -- ModelTrigger
  virtual G4bool ModelTrigger(const G4FastTrack &);
  // -- User method DoIt
  virtual void DoIt(const G4FastTrack&, G4FastStep&);

private:
  void AssignSpotAndCallHit(const G01EnergySpot &eSpot);
  void FillFakeStep(const G01EnergySpot &eSpot);
  void Explode(const G4FastTrack&);
  void BuildDetectorResponse();
  
private:
  G4Step                         *fFakeStep;
  G4StepPoint                    *fFakePreStepPoint, *fFakePostStepPoint;
  G4TouchableHandle              fTouchableHandle;
  G4Navigator                    *fpNavigator;
  G4bool                         fNaviSetup;

  std::vector<G01EnergySpot> feSpotList;

};
#endif
