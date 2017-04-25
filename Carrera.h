#include <iostream>
#include <stdlib.h>
#include <vector>
#include <utility>
#include "Semestre.h"
#include "helpers.h"

class Carrera{
private:
  std::vector<Semestre*> semestres;
  int init_al;
  int num_semestres;
  int num_alumnos_semestre;
  int id;
  //std::vector<std::pair<float, int>> matrix;
  int num_filas;
  int lim_inf;
  int lim_sup;
public:
  Carrera(int, int, int);
  ~Carrera();
  void AvanzarSemestre();
  int alpha();
  int AlumnosNuevoIngreso();
  void printInfo();
  void CrearTabla();
};
