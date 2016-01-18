#pragma once

#include "ObjetoCompuesto3D.h"
#include "Cubo.h"
#include "Ficha.h"

class Coche : public ObjetoCompuesto3D {
	Cubo*   _chasis;
	Ficha** _ruedas;

public:
	Coche();
	virtual void dibuja();
};
