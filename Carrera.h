#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Semestre.h"

class Carrera{
private:
  std::vector<Semestre*> semestres;
  int init_al;
  int num_semestres;
  int num_alumnos_semestre;
  int id;
public:
  Carrera(int, int, int);
  ~Carrera();
  void AvanzarSemestre();
  int alpha();
  int AlumnosNuevoIngreso();
  void printInfo();
};
