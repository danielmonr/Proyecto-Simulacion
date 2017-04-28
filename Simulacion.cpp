#include "Simulacion.h"

Simulacion::~Simulacion(){
  //delete(institucion);
}

Simulacion::Simulacion(int NCarreras,int NSemestres,int NAlumnos, int NP) :
  NCarreras(NCarreras),NAlumnos(NAlumnos), NSemestres(NSemestres), NProfesores(NP)
{
  institucion = new Institucion(1, NCarreras, NSemestres, NAlumnos, NProfesores);
  //institucion->printInfo();
  PrintState();
}

void Simulacion::CorrerSimulacion(){
  institucion->AvanzarSemestre();
  PrintState();
}

void Simulacion::PrintState(){
  Helper::clearScreen();
  int val = (NAlumnos*NSemestres)/50;
  int cant = val*institucion->TotalAlumnos();
  int cantg = val*institucion->TotalGraduados();
  int cantr = val*institucion->TotalReprobados();
  int cante = val*institucion->TotalExpulsados();
  int cantd = val*institucion->num_drops;
  cout << "Alumnos institucion:" << string(cant, '|') << endl;
  cout << "Graduados: " << string(cantg, '|') << endl;
  cout << "Reprobados:" << string(cantr, '|') << endl;
  cout << "Expulsados:" << string(cante, '|') << endl;
  cout << "Drop Outs: " << string(cantd, '|') << endl;
  for(auto carr:institucion->carreras){
    cout << "Carrera " << carr->id << ":" << string(val*carr->alumnos.size(), '|')<<endl;
  }
}
