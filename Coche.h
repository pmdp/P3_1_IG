#pragma once

#include "ObjetoCompuesto3D.h"

class Coche : public ObjetoCompuesto3D {
public:
	Coche();
	void girar(float angle);
};
