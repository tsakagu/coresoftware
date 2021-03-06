// Tell emacs that this is a C++ source
// This file is really -*- C++ -*-.
#ifndef G4DETECTORS_PHG4INNERHCALDETECTOR_H
#define G4DETECTORS_PHG4INNERHCALDETECTOR_H

#include <g4main/PHG4Detector.h>

// cannot fwd declare G4RotationMatrix, it is a typedef pointing to clhep
#include <Geant4/G4RotationMatrix.hh>

#include <CGAL/Exact_circular_kernel_2.h>
#include <CGAL/point_generators_2.h>

#include <map>
#include <set>
#include <vector>

class G4AssemblyVolume;
class G4LogicalVolume;
class G4VPhysicalVolume;
class G4VSolid;
class PHG4InnerHcalDisplayAction;
class PHG4InnerHcalSubsystem;
class PHParameters;

class PHG4InnerHcalDetector : public PHG4Detector
{
 public:
  typedef CGAL::Exact_circular_kernel_2 Circular_k;
  typedef CGAL::Point_2<Circular_k> Point_2;

  //! constructor
  PHG4InnerHcalDetector(PHG4InnerHcalSubsystem *subsys, PHCompositeNode *Node, PHParameters *parameters, const std::string &dnam);

  //! destructor
  virtual ~PHG4InnerHcalDetector();

  //! construct
  virtual void Construct(G4LogicalVolume *world);

  virtual void Print(const std::string &what = "ALL") const;

  //!@name volume accessors
  //@{
  int IsInInnerHcal(G4VPhysicalVolume *) const;
  //@}

  void SuperDetector(const std::string &name) { m_SuperDetector = name; }
  const std::string SuperDetector() const { return m_SuperDetector; }
  int get_Layer() const { return m_Layer; }
  G4VSolid *ConstructSteelPlate(G4LogicalVolume *hcalenvelope);
  G4VSolid *ConstructScintillatorBox(G4LogicalVolume *hcalenvelope);
  void ShiftSecantToTangent(Point_2 &lowleft, Point_2 &upleft, Point_2 &upright, Point_2 &lowright);

  G4AssemblyVolume *ConstructHcalScintillatorAssembly(G4LogicalVolume *hcalenvelope);
  void ConstructHcalSingleScintillators(G4LogicalVolume *hcalenvelope);
  int CheckTiltAngle() const;
  int ConsistencyCheck() const;
  void SetTiltViaNcross();
  std::pair<int, int> GetLayerTowerId(G4VPhysicalVolume *volume) const;

 protected:
  int ConstructInnerHcal(G4LogicalVolume *sandwich);
  double x_at_y(Point_2 &p0, Point_2 &p1, double yin);
  PHG4InnerHcalDisplayAction *m_DisplayAction;
  PHParameters *m_Params;
  G4AssemblyVolume *m_ScintiMotherAssembly;
  double m_InnerRadius;
  double m_OuterRadius;
  double m_SizeZ;
  double m_ScintiTileX;
  double m_ScintiTileXLower;
  double m_ScintiTileXUpper;
  double m_ScintiTileZ;
  double m_ScintiTileThickness;
  double m_ScintiInnerGap;
  double m_ScintiOuterGap;
  double m_ScintiOuterRadius;
  double m_TiltAngle;
  double m_EnvelopeInnerRadius;
  double m_EnvelopeOuterRadius;
  double m_EnvelopeZ;
  double m_VolumeEnvelope;
  double m_VolumeSteel;
  double m_VolumeScintillator;

  int m_NumScintiPlates;
  int m_NumScintiTiles;

  int m_Active;
  int m_AbsorberActive;

  int m_Layer;
  std::string m_SuperDetector;
  std::set<G4VPhysicalVolume *> m_SteelAbsorberPhysVolSet;
  std::map<G4VPhysicalVolume *, std::pair<int, int>> m_ScintiTilePhysVolMap;
  std::vector<G4VSolid *> m_ScintiTilesVec;
  std::string m_ScintiLogicNamePrefix;
};

#endif  // G4DETECTORS_PHG4INNERHCALDETECTOR_H
