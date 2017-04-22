#include <iostream>
#include <stdlib.h>

class Semestre{
private:
  int id;
public:
  Semestre(int, int);
  ~Semestre();
  void printInfo();
  int num_alumnos;
};
