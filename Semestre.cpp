#include "Semestre.h"

Semestre::Semestre(int n) : num_alumnos(n){

}

Semestre::~Semestre(){

}

void printInfo(){
  std::cout << "Numero de Alumnos: " << num_alumnos << std::endl;
}
