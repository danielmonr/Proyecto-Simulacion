#include "Alumno.h"

Alumno::Alumno(int s){
  semestre = s;
  reprobadas = 0;
}

bool Alumno::aprobar(){
  srand((int) time(NULL));
  if(rand()%101 > 96){
    reprobadas++;
    return false;
  }
  semestre++;
  return true;
}
