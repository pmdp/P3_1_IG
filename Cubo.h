#pragma once

#include "Malla.h"

class Cubo : public Malla {
public:
	Cubo() : Malla(new TAfin()) {}
	void dibuja();
};
