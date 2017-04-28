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
  int root;
public:
  Institucion(int, int, int, int, int);
  ~Institucion();
  void AvanzarSemestre();
  int TotalAlumnos();
  int TotalGraduados();
  int TotalReprobados();
  int TotalExpulsados();
  void printInfo();
  int NPExternos;
  int num_drops;
  std::vector<Carrera*> carreras;
};
