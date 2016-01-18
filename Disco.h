#pragma once

#include <GL/glu.h>
#include "ObjetoCuadrico.h"

class Disco: public ObjetoCuadrico
{
private:
	GLUquadricObj* _disco;
	float _inner;
	float _outer;
	float _slices;
	float _loops;

public:
	Disco(float inner, float outer, float slices, float loops);
	virtual void dibuja();
};

