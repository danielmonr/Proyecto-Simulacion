#include <iostream>
#include <stdlib.h>
#include <vector>
#include "Carrera.h"

class Institucion{
private:
  int id;
  int NCarreras;
  int NSemestres;
  int Nalumnos;
  int NProfesores;
  int num_drops;
  int root;
  std::vector<Carrera*> carreras;
public:
  Institucion(int, int, int, int);
  ~Institucion();
  void AvanzarSemestre();
  void printInfo();
};
