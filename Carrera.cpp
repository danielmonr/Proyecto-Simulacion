#include "Carrera.h"

Carrera::Carrera(int i,int n,int s) : id(i),num_semestres(n), num_alumnos_semestre(s){
  init_al = num_alumnos_semestre;
  for(int i = 0; i < num_semestres; ++i){
    semestres.push_back(new Semestre(i+1, num_alumnos_semestre));
  }
  CrearTabla();
}

Carrera::~Carrera(){
}

void Carrera::printInfo(){
  std::cout << "Carrera" << id << " info: " << std::endl;
  std::cout << "\tNumero de Semestres: " << num_semestres << std::endl;
  int sum = 0;
  for(auto item:semestres){
    std::cout << "\t";
    item->printInfo();
    sum += item->num_alumnos;
  }
  std::cout << "\tTotal de Alumnos: " << sum << std::endl;
}

void Carrera::AvanzarSemestre(){
  int quedadosSiguiente = alpha();
  int quedadosPresente = 0;
  for(int i = semestres.size()-2; i > 0; --i){
    quedadosPresente = alpha();
    std::cout << "Alpha de " << i << ": " << quedadosSiguiente << '\n';
    if(i == semestres.size()-2){
      std::cout << "Graduados: " << (semestres.at(i+1)->num_alumnos)- quedadosSiguiente << std::endl;
    }
    semestres.at(i+1)->num_alumnos = quedadosSiguiente + semestres.at(i)->num_alumnos - quedadosPresente;
    quedadosSiguiente = quedadosPresente;
  }
  //semestres.at(0)->num_alumnos = 0;
  semestres.at(0)->num_alumnos = AlumnosNuevoIngreso() + quedadosSiguiente;
}

int Carrera::alpha(){
  /*int root = 165231, a = 8121, m = 134456, c = 28411;
  root = Helper::congruencial(root, a, m, c);
  float aleatorio = (float)root/(float)m;
  // Numero de alumnos que se quedan en el semestre
  for(auto fila:tabla_t.matrix){
    if(aleatorio < fila.first){
      return fila.second;
    }
  }*/

  return 2;
}

int Carrera::AlumnosNuevoIngreso(){
  srand((int)time(NULL));
  int por = init_al/10;
  return (rand()%(int)(por*2))+ (init_al - por);
}

void Carrera::CrearTabla(){
  /*num_filas = num_alumnos_semestre / 10;
  lim_inf = 0;
  lim_sup = num_alumnos_semestre / 10;
  float per_adv = (1/(float)(num_filas));
  float per = per_adv;
  int val = lim_inf;
  for(int i = 0; i < num_filas; ++i){
    matrix.push_back(std::make_pair(per,val));
    per += per_adv;
    val += (lim_sup - lim_inf)/num_filas;
  }*/
}
