ALL: proy
.PHONY=clean

clean:
	\rm -rf proy

proy: Simulacion.h Simulacion.cpp Inscripciones.cpp
	g++ --std=c++11 -o proy Inscripciones.cpp Simulacion.cpp
