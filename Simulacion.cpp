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

  //PrintState();
}

void Simulacion::PrintState(){
  Helper::clearScreen();
  float val = ((NAlumnos*NSemestres*NCarreras)/100)*2;
  int cant = institucion->TotalAlumnos()/val;
  int cantg = institucion->TotalGraduados()/val;
  int cantr = institucion->TotalReprobados()/val;
  int cante = institucion->TotalExpulsados()/val;
  int cantd = institucion->num_drops/val;
  cout << "Alumnos institucion:" << string(cant, '|') << endl;
  cout << "Graduados: " << string(cantg, '|') << endl;
  cout << "Reprobados:" << string(cantr, '|') << endl;
  cout << "Expulsados:" << string(cante, '|') << endl;
  cout << "Drop Outs: " << string(cantd, '|') << endl;
  for(auto carr:institucion->carreras){
    cout << "Carrera " << carr->id << ":" << string(carr->alumnos.size()/val, '|')<<endl;
  }
}

void Simulacion::DescribeState(){
  Helper::clearScreen();
  float val = ((NAlumnos*NSemestres*NCarreras)/100)*2;
  int total = institucion->TotalAlumnos();
  int totalg = institucion->TotalGraduados();
  int totalr = institucion->TotalReprobados();
  int totale = institucion->TotalExpulsados();
  int totald = institucion->num_drops;
  int totalp = institucion->NPExternos;
  cout << "Alumnos institucion:" << total << endl;
  cout << "Graduados: " << totalg << endl;
  cout << "Reprobados:" << totalr << endl;
  cout << "Expulsados:" << totale << endl;
  cout << "Drop Outs: " << totald << endl;
  cout << "Profesores Externos: " << totalp << endl;
  for(auto carr:institucion->carreras){
    cout << "Carrera " << carr->id << ":" << carr->alumnos.size() <<endl;
  }
}
