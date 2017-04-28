#include "Alumno.h"

Alumno::Alumno(int s){
  semestre = s;
}

bool Alumno::aprobar(){
  srand((int) time(NULL));
  if(rand()%101 < 70){
    reprobadas++;
    return false;
  }
  semestre++;
  return true;
}
