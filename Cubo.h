#pragma once

#include "Malla.h"

class Cubo : public Malla {
private:
	void initCube();

public:
	Cubo(int numText, GLuint* tex, int numCaraTex);
	Cubo();
};
