#pragma once

#include <list>

#include "ObjetoCompuesto3D.h"
#include "Cubo.h"

class Tablero : public ObjetoCompuesto3D {
private:
	std::list<Cubo*> _cubos;
	int _largo, _alto, _ancho;
	int _numCubos;

public:
	Tablero(int largo, int alto, int ancho);
	virtual void dibuja();
};
