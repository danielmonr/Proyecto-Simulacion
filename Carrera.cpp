#include "Carrera.h"

Carrera::Carrera(int i,int n,int s) : id(i),num_semestres(n), num_alumnos_semestre(s){
  init_al = num_alumnos_semestre;
  for(int i = 0; i < num_semestres; ++i){
    for (int j = 0; j < init_al; ++j){
      alumnos.push_back(new Alumno(i+1));
    }
  }
  num_reprobados = 0;
  num_expulsados = 0;
  num_graduados = 0;
  //CrearTabla();
}

Carrera::~Carrera(){
}

void Carrera::printInfo(){
  std::cout << "Carrera" << id << " info: " << std::endl;
  std::cout << "\tNumero de Semestres: " << num_semestres << std::endl;
  int sum = 0;
  /*for(auto item:semestres){
    std::cout << "\t";
    item->printInfo();
    sum += item->num_alumnos;
  }*/
  std::cout << "\tTotal de Alumnos: " << alumnos.size() << std::endl;
}

void Carrera::AvanzarSemestre(){
  num_reprobados = 0;
  num_expulsados = 0;
  for (auto al:alumnos){
    num_reprobados = (al->aprobar())? num_reprobados : num_reprobados+1;
  }
  for(int i = 0; i < alumnos.size(); ++i){
    //std::cout << "Alumnos:" << alumnos.size() << " - i: " << i << "\n";
    if(alumnos.at(i)->reprobadas >= 3){
      //alumnos.erase(alumnos.begin() + i);
      std::cout << "######################Erase, long:" << alumnos.at(i)->reprobadas << "\n";
      num_expulsados++;
      i = (i > 0)? i-1: 0;
    }
    if(alumnos.at(i)->semestre > num_semestres){
      num_graduados++;
      alumnos.erase(alumnos.begin() + i);
      //std::cout << "######################Erase, long:" << alumnos.size() << "\n";

      i = (i > 0)? i-1: 0;
    }
  }
}


void Carrera::AlumnosNuevoIngreso(){
  srand((int)time(NULL));
  int por = init_al/10;
  int numnuev = (rand()%(int)(por*2))+ (init_al - por);
  for(int i = 0; i < numnuev; ++i){
    alumnos.push_back(new Alumno(1));
  }
}
