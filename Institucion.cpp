#include "Institucion.h"

Institucion::Institucion(int id, int nc, int ns, int na) : id(id), NCarreras(nc), NSemestres(ns), Nalumnos(na){
  for(int i = 0; i < NCarreras; ++i){
    carreras.push_back(Carrera(i+1, NSemestres, Nalumnos));
  }
}

Institucion::~Institucion(){

}

void Institucion::printInfo(){
  std::cout << "Institucion " << id << " info:" << std::endl;
  std::cout << "\tNumero de Carreras: " << NCarreras << std::endl;
  for(auto item:carreras){
    std::cout << "\t";
    item.printInfo();
  }
}
