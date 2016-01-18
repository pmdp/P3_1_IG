#pragma once

#include <GL/glu.h>
#include "ObjetoCuadrico.h"

class Esfera : public ObjetoCuadrico
{
private:
	GLUquadricObj* _esfera;
	float _radio;
	float _slices;
	float _stacks;

public:
	Esfera(float radio, float slices, float stacks);
	virtual void dibuja();
};

