#pragma once

#include "ObjetoCompuesto3D.h"
#include "Cubo.h"
#include "Ficha.h"

class Coche : public ObjetoCompuesto3D {
private:
	ObjetoCompuesto3D* _coche;
	Objeto3D**		   _ruedas;
	Objeto3D*		   _chasis;

	int _numRuedas;

public:
	Coche();
	void dibuja();
};
