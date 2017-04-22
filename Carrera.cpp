#include "Carrera.h"

Carrera::Carrera(int i,int n,int s) : id(i),num_semestres(n), num_alumnos_semestre(s){
  for(int i = 0; i < num_semestres; ++i){
    semestres.push_back(Semestre(i+1, num_alumnos_semestre));
  }
}

Carrera::~Carrera(){
}

void Carrera::printInfo(){
  std::cout << "Carrera" << id << " info: " << std::endl;
  std::cout << "\tNumero de Semestres: " << num_semestres << std::endl;
  int sum = 0;
  for(auto item:semestres){
    std::cout << "\t";
    item.printInfo();
    sum += item.num_alumnos;
  }
  std::cout << "\tTotal de Alumnos: " << sum << std::endl;
}
