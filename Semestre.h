#include <iostream>
#include <stdlib.h>

class Semestre{
private:
  int id;
  int quedados;
public:
  Semestre(int, int);
  ~Semestre();
  void printInfo();
  int num_alumnos;
};
