#include "Carrera.h"

Carrera::Carrera(int i,int n,int s) : id(i),num_semestres(n), num_alumnos_semestre(s){
  init_al = num_alumnos_semestre;
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

void Carrera::AvanzarSemestre(){
  int quedadosAnterior = 0;
  int quedadosPresente = 0;
  for(int i = 0; i < semestres.size(); ++i){
    quedadosPresente = alpha();
    std::cout << "Alpha de " << i << ": " << quedadosPresente << '\n';
    if(i == semestres.size()-1){
      std::cout << "Graduados: " << (semestres.at(i).num_alumnos)- quedadosPresente << std::endl;
    }
    semestres.at(i).num_alumnos = quedadosPresente;
    semestres.at(i).num_alumnos += (i > 0)? (semestres.at(i-1).num_alumnos) - quedadosAnterior : AlumnosNuevoIngreso();
    quedadosAnterior = quedadosPresente;
  }
}

int Carrera::alpha(){
  // Numero de alumnos que se quedan en el semestre
  return 0;
}

int Carrera::AlumnosNuevoIngreso(){
  srand((int)time(NULL));
  int por = init_al/10;
  return (rand()%(int)(por*2))+ (init_al - por);
}
