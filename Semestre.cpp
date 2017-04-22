#include "Semestre.h"

Semestre::Semestre(int i,int n) : id(i),num_alumnos(n){

}

Semestre::~Semestre(){

}

void Semestre::printInfo(){
  std::cout << "Semestre " << id << " info:\n";
  std::cout << "\tNumero de Alumnos: " << num_alumnos << std::endl;
}
