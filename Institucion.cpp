#include "Institucion.h"

Institucion::Institucion(int id, int nc, int ns, int na) : id(id), NCarreras(nc), NSemestres(ns), Nalumnos(na){
  for(int i = 0; i < NCarreras; ++i){
    carreras.push_back(new Carrera(i+1, NSemestres, Nalumnos));
  }
  num_drops = 0;
  root = 165231;
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
  Alumno* temp;
  for(auto item:carreras){
    item->AvanzarSemestre();
    for(int i = 0; i <item->alumnos.size(); ++i){
      root = Helper::congruencial(root, a, m, c);
      if(root/m < 0.7){
      }
      else if(root/m < 0.75){
        num_drops++;
        item->alumnos.erase(item->alumnos.begin()+i);
      }
      else{
        int cont = 0;
        for(auto carr:carreras){
          if(carr->id != item->id && (root/m) < (divi*cont)+(0.75+divi)){
            temp = item->alumnos.at(i);
            item->alumnos.erase(item->alumnos.begin()+i);
            carr->alumnos.push_back(temp);
            temp->semestre = (temp->semestre > 2)? 2 : temp->semestre;
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
}
