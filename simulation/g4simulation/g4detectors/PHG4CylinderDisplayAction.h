// Tell emacs that this is a C++ source
// This file is really -*- C++ -*-.
#ifndef G4DETECTORS_PHG4CYLINDERDISPLAYACTION_H
#define G4DETECTORS_PHG4CYLINDERDISPLAYACTION_H

#include <g4main/PHG4DisplayAction.h>

class G4VisAttributes;
class G4LogicalVolume;
class PHParameters;

class PHG4CylinderDisplayAction : public PHG4DisplayAction
{
 public:
  PHG4CylinderDisplayAction(const std::string &name, PHParameters *parameters);

  virtual ~PHG4CylinderDisplayAction();

  void ApplyDisplayAction(G4VPhysicalVolume *physvol);
  void SetMyVolume(G4LogicalVolume *vol) { m_MyVolume = vol; }


 private:
  PHParameters *m_Params;
  G4LogicalVolume *m_MyVolume;
  G4VisAttributes *m_VisAtt;
};

#endif  // G4DETECTORS_PHG4CYLINDERDISPLAYACTION_H
