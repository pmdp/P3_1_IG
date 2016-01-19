#pragma once

#include "ObjetoCompuesto3D.h"
#include "Cubo.h"

class Tablero : public ObjetoCompuesto3D {
private:
	Cubo** _cubos;
	int _largo, _alto, _ancho;
	int _numCubos;

public:
	Tablero(int largo, int alto, int ancho);
	void dibuja();
};
