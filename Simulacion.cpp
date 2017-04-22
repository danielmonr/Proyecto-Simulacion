#include "Simulacion.h"

Simulacion::~Simulacion(){
  //delete(institucion);
}

Simulacion::Simulacion(int NCarreras,int NSemestres,int NAlumnos) :
  NCarreras(NCarreras),NAlumnos(NAlumnos), NSemestres(NSemestres)
{
  institucion = new Institucion(1, NCarreras, NSemestres, NAlumnos);
  institucion->printInfo();

}
