#pragma once

#include "ObjetoCompuesto3D.h"
#include "Cubo.h"
#include "Ficha.h"

class Coche : public ObjetoCompuesto3D {
private:
	ObjetoCompuesto3D* _coche;
	Objeto3D*		   _rueda1;
	//Objeto3D*		   _rueda2;
	//Objeto3D*		   _rueda3;
	//Objeto3D*		   _rueda4;
	//Objeto3D*		   _chasis;

	int _numRuedas;

public:
	Coche();
	//void dibuja();
};
