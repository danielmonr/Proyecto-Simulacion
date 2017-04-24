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
  std::vector<Carrera> carreras;
public:
  Institucion(int, int, int, int);
  ~Institucion();
  void AvanzarSemestre();
  void printInfo();
};
