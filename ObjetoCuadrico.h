#pragma once

#include "Objeto3D.h"

class ObjetoCuadrico : public Objeto3D {
public:
	ObjetoCuadrico(TAfin* mt) : Objeto3D(mt) {}
	void dibuja();
};

