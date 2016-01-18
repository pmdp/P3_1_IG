#pragma once

#include "ObjetoCompuesto3D.h"
#include "Cilindro.h"
#include "Esfera.h"

class Farola :public ObjetoCompuesto3D {
	Cilindro _base;
	Esfera	 _cabeza;

public:
	Farola();
	virtual void dibuja();
};
