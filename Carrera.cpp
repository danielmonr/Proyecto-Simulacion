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
  for (auto al:alumnos){
    num_reprobados = (al->aprobar())? num_reprobados : num_reprobados+1;
  }
  for(int i = 0; i < alumnos.size(); ++i){
    if(alumnos.at(i)->reprobadas >= 3){
      alumnos.erase(alumnos.begin() + i);
      num_expulsados++;
      i--;
    }
    if(alumnos.at(i)->semestre > num_semestres){
      num_graduados++;
      alumnos.erase(alumnos.begin() + i);
      i--;
    }
  }
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

void Carrera::AlumnosNuevoIngreso(){
  srand((int)time(NULL));
  int por = init_al/10;
  int numnuev = (rand()%(int)(por*2))+ (init_al - por);
  for(int i = 0; i < numnuev; ++i){
    alumnos.push_back(new Alumno(1));
  }
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
