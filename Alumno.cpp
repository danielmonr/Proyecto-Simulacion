#include "Alumno.h"

Alumno::Alumno(int s){
  semestre = s;
  reprobadas = 0;
}

bool Alumno::aprobar(){
  //srand((int) time(NULL));
  int r = rand()%101;
  if(r > 96){
    reprobadas++;
    //std::cout << "R = " << reprobadas << '\n';
    return false;
  }
  //std::cout << "Rand: " << r << '\n';
  semestre++;
  return true;
}
