#pragma once

#include <GL/gl.h>
#include "PV3D.h"

class TAfin {

public:
	TAfin();
	void traslada(PV3D* v);
	void rota(float angle, float x, float y, float z);
	void escala(PV3D* v);
	void postMultiplica(GLfloat* m1);
	GLfloat m[16];
};

