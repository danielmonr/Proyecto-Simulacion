ALL: proy
.PHONY=clean

clean:
	\rm -rf proy *.o

carrera.o: Carrera.h Carrera.cpp
	g++ --std=c++11 -c Carrera.cpp -o carrera.o

institucion.o: Institucion.h Institucion.cpp
	g++ --std=c++11 -c Institucion.cpp -o institucion.o

semestre.o: Semestre.h Semestre.cpp
	g++ --std=c++11 -c Semestre.cpp -o semestre.o

simulacion.o: Simulacion.cpp Simulacion.h
	g++ --std=c++11 -c Simulacion.cpp -o simulacion.o

proy: Inscripciones.cpp simulacion.o semestre.o institucion.o carrera.o
	g++ --std=c++11 -o proy Inscripciones.cpp simulacion.o semestre.o institucion.o carrera.o
