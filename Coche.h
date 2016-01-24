#pragma once

#include "ObjetoCompuesto3D.h"
#include "Cilindro.h"

class Coche : public ObjetoCompuesto3D {
public:
	Coche();
	void girar(float angle);
	PV3D* vDireccion;
	Cilindro* faro1;
	Cilindro* faro2;
};
