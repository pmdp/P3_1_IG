#pragma once

#include <GL/gl.h>
#include "PV3D.h"

class TAfin {

public:
	TAfin();
	void translada(PV3D* v);
	void rota(float angle, float x, float y, float z);
	void postMultiplica(GLfloat* m1);

	GLfloat _m[16];
};

