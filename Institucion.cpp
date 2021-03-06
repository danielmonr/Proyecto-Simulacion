#include "Institucion.h"

Institucion::Institucion(int id, int nc, int ns, int na, int np) : id(id), NCarreras(nc), NSemestres(ns), Nalumnos(na), NProfesores(np){
  for(int i = 0; i < NCarreras; ++i){
    carreras.push_back(new Carrera(i+1, NSemestres, Nalumnos));
  }
  num_drops = 0;
  srand((int)time(NULL));
  root = (rand()%134000)+450;
  NPExternos = 0;
}

Institucion::~Institucion(){

}

void Institucion::printInfo(){
  std::cout << "Institucion " << id << " info:" << std::endl;
  std::cout << "\tNumero de Carreras: " << NCarreras << std::endl;
  for(auto item:carreras){
    std::cout << "\t";
    item->printInfo();
  }
}

void Institucion::AvanzarSemestre(){
  int a = 8121, m = 134456, c = 28411;
  float divi = 25/((float)NCarreras-1);
  num_drops = 0;
  int total, diff = 0;
  for(auto item:carreras){
    Alumno* temp;
    item->AvanzarSemestre();
    for(int i = 0; i < item->alumnos.size(); ++i){
      root = Helper::congruencial(root, a, m, c);
      if((float)root/m < 0.7){
      }
      else if((float)root/m < 0.75){
        num_drops++;
        item->alumnos.erase(item->alumnos.begin()+i);
        i = (i > 0)? i-1: 0;
      }
      else{
        int cont = 0;
        for(auto carr:carreras){
          if(carr->id != item->id && ((float)root/m) < ((divi/100)*cont)+(0.75+(divi/100))){
            temp = item->alumnos.at(i);
            item->alumnos.erase(item->alumnos.begin()+i);
            carr->alumnos.push_back(temp);
            temp->semestre = (temp->semestre > 2)? 2 : temp->semestre;
            i = (i > 0)? i-1: 0;
            break;
          }
          else{
            cont++;
          }
        }
      }
    }
    item->AlumnosNuevoIngreso();
  }
  NPExternos = (TotalAlumnos() - (NProfesores*100)) / 100;
  if(NPExternos < 0)
    NPExternos = -1;
  NPExternos++;
}

int Institucion::TotalAlumnos(){
  int n = 0;
  for(auto carr:carreras){
    n += carr->alumnos.size();
  }
  return n;
}

int Institucion::TotalGraduados(){
  int n = 0;
  for(auto carr:carreras){
    n += carr->num_graduados;
  }
  return n;
}
int Institucion::TotalExpulsados(){
  int n = 0;
  for(auto carr:carreras){
    n += carr->num_expulsados;
  }
  return n;
}
int Institucion::TotalReprobados(){
  int n = 0;
  for(auto carr:carreras){
    n += carr->num_reprobados;
  }
  return n;
}
