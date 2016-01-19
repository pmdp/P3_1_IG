#pragma once

#include <GL/glu.h>
#include "ObjetoCuadrico.h"

class Cilindro : public ObjetoCuadrico
{
private:
	GLUquadricObj* _cilindro;
	float _radio1;
	float _radio2;
	float _alto;
	float _slices;
	float _stacks;

public:
	Cilindro(float radio1, float radio2, float alto, float slices, float stacks);
	void dibuja();
};

