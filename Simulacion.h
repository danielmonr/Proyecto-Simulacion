#include <iostream>
#include <fstream>
#include <stdlib.h>

#define HOURS_PER_CLASSR 7
#define HOURS_PER_CLASS 1
#define HOURS_PER_WEEK_PER_COURSE 2

using namespace std;

class Simulacion{
	private:
		const int NAulas,CAula,NCarreras,NMateriasTC,NMateriasE,NProfesoresP,NAlumnos,NMateriasS,NmateriasP;
		int MAX_AL, OUT_AL, NProfesoresE, NUM_SEM;
	protected:
	public:
		Simulacion(int,int,int,int,int,int,int,int,int);
		~Simulacion();
};
