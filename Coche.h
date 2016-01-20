#pragma once

#include "ObjetoCompuesto3D.h"
#include "Cubo.h"
#include "Ficha.h"

class Coche : public ObjetoCompuesto3D {
private:
	int _numRuedas;

public:
	Coche();
};
