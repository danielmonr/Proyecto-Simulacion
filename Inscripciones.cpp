#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include "Simulacion.h"
#include "helpers.h"

using namespace std;

std::vector<Simulacion> sims;

void CrearSimulaciones(string);

int main(int argc, char* argv[]){
	if(argc > 2){
		cout << "Not implemented.\n";
		exit(0);
	}

	/*Institucion* inst = new Institucion(1,4,6,20);
	inst->printInfo();*/

	string archivo = (argc>1)? string(argv[1]) : "valoresIniciales.csv";
	CrearSimulaciones(archivo);

	cout << "Numero de semestres: ";
	int numsims;
	cin >> numsims;

	for(auto simulacion:sims){
		for(int i = 0; i < numsims; ++i){
			simulacion.CorrerSimulacion();
			sleep(1);
		}
	}
}

void CrearSimulaciones(string f){
	string line;
	ifstream ifs;
	ifs.open(f, ifstream::in);
	getline(ifs, line);
	while(getline(ifs, line)){
		int vars[4];
		int cont = 0;
		string temp = "";
		line += ",";
		for(int i = 0; i < line.length(); ++i){
			if(line[i] == ','){
				vars[cont] = stoi(temp);
				temp = "";
				cont++;
			}
			else{
				temp += line[i];
			}
		}
		sims.push_back(Simulacion(vars[0],vars[1],vars[2], vars[3]));
	}
	ifs.close();
}
