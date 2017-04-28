#include <iostream>
#include <stdlib.h>
#include <vector>
#include <utility>
#include "Alumno.h"
#include "helpers.h"

class Carrera{
private:
  int init_al;
  int num_semestres;
  int num_alumnos_semestre;

  //std::vector<std::pair<float, int>> matrix;
  int num_filas;
  int lim_inf;
  int lim_sup;
public:
  int num_reprobados;
  int num_expulsados;
  int num_graduados;
  int id;
  std::vector<Alumno*> alumnos;
  Carrera(int, int, int);
  ~Carrera();
  void AvanzarSemestre();
  int alpha();
  void AlumnosNuevoIngreso();
  void printInfo();
  void CrearTabla();
};
