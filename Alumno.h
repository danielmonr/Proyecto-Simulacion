#include <iostream>
#include <stdlib.h>
#include <time.h>

class Alumno{
public:
  int semestre;
  int reprobadas;
  Alumno(int);
  ~Alumno();
  bool aprobar();
};
