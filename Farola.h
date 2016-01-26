#pragma once

#include "ObjetoCompuesto3D.h"
#include "Cilindro.h"
#include "Esfera.h"

class Farola : public ObjetoCompuesto3D {
public:
	Farola();
	bool caida;
};
