#ifndef G4VERTEX_GLOBALVERTEXRECO_H
#define G4VERTEX_GLOBALVERTEXRECO_H

//===========================================================
/// \file GlobalVertexReco.h
/// \brief reconstruct the best possible vertexes by
/// combining results from multiple detectors
/// \author Mike McCumber
//===========================================================

#include <fun4all/Fun4AllReturnCodes.h>
#include <fun4all/SubsysReco.h>

#include <phool/PHTimeServer.h>

class PHCompositeNode;

/// \class GlobalVertexReco
///
/// \brief simple truth vertex smearing algorithm
///
class GlobalVertexReco : public SubsysReco
{
 public:
  GlobalVertexReco(const std::string &name = "GlobalVertexReco");
  virtual ~GlobalVertexReco();

  int Init(PHCompositeNode *topNode);
  int InitRun(PHCompositeNode *topNode);
  int process_event(PHCompositeNode *topNode);
  int End(PHCompositeNode *topNode);

  void set_x_defaults(float xdefault, float xerr)
  {
    _xdefault = xdefault;
    _xerr = xerr;
  }
  void set_y_defaults(float ydefault, float yerr)
  {
    _ydefault = ydefault;
    _yerr = yerr;
  }
  void set_t_defaults(float tdefault, float terr)
  {
    _tdefault = tdefault;
    _terr = terr;
  }

 private:
  int CreateNodes(PHCompositeNode *topNode);

  float _xdefault, _xerr;
  float _ydefault, _yerr;
  float _tdefault, _terr;
};

#endif  // G4VERTEX_GLOBALVERTEXRECO_H
