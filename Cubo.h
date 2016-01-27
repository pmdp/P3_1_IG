#pragma once

#include "Malla.h"

class Cubo : public Malla {
	void initCube();

public:
	Cubo(int numText, GLuint* tex, int numCaraTex);
	Cubo();
};
