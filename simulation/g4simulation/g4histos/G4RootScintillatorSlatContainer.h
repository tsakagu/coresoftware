#ifndef G4HISTOS_G4ROOTSCINTILLATORSLATCONTAINER_H
#define G4HISTOS_G4ROOTSCINTILLATORSLATCONTAINER_H

#include <phool/PHObject.h>

class PHG4ScintillatorSlat;
class G4RootScintillatorSlat;
class TClonesArray;

class G4RootScintillatorSlatContainer : public PHObject
{
 public:
  G4RootScintillatorSlatContainer();
  virtual ~G4RootScintillatorSlatContainer();

  void Reset();

  G4RootScintillatorSlat* AddSlat(const PHG4ScintillatorSlat& slat);

  void set_idet(const int i) { idet = i; }
  int get_idet() const { return idet; }

  void set_etotal(const float e) { etotal = e; }
  float get_etotal() const { return etotal; }

  void set_eion(const float e) { eion = e; }
  float get_eion() const { return eion; }

  void set_leakage(const float f) { leakage = f; }
  float get_leakage() const { return leakage; }

  void set_event(const int i) { event = i; }
  int get_event() const { return event; }

  void identify(std::ostream& os = std::cout) const;

 protected:
  int idet;
  float etotal;
  float eion;
  float leakage;
  int event;
  TClonesArray* SnglSlats;

  ClassDef(G4RootScintillatorSlatContainer, 1)
};

#endif
