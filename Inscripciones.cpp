#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <semaphore.h>
#include "Simulacion.h"
#include "helpers.h"

using namespace std;

std::vector<Simulacion*> sims;

pthread_t print_th, getch_th;
pthread_mutex_t mutex;

char typeprint = 'b';

void CrearSimulaciones(string);
void* Print(void*);
void* GetCh(void*);

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

	pthread_mutex_lock(&mutex);

	for(auto simulacion:sims){
		pthread_create(&print_th, 0, Print, (void*)simulacion);
		pthread_create(&getch_th, 0, GetCh, NULL);
		for(int i = 0; i < numsims; ++i){
			simulacion->CorrerSimulacion();
			pthread_mutex_unlock(&mutex);
			sleep(1);
		}
		typeprint = 'e';
		pthread_cancel(getch_th);
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
		sims.push_back(new Simulacion(vars[0],vars[1],vars[2], vars[3]));
	}
	ifs.close();
}

void* Print(void* v){
	Simulacion* s = (Simulacion*) v;
	while (true) {
		pthread_mutex_lock(&mutex);
		switch (typeprint) {
			case 'b':
				s->PrintState();
				break;
			case 'd':
				s->DescribeState();
				break;
			case 'e':
				pthread_exit(0);
				break;
			default:
				cout << "Please choose a correct option(b/d).\n";
				break;
		}
	}
}

void* GetCh(void *v){
	while(true){
		cin >> typeprint;
		if(typeprint == 'b' || typeprint == 'd'){
			pthread_mutex_unlock(&mutex);
		}
		else if(typeprint == 'e'){
			pthread_mutex_unlock(&mutex);
			pthread_exit(0);
		}
	}
}
