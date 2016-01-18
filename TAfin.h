#pragma once

#include <GL/gl.h>

class TAfin {
public:
	TAfin();

	TAfin translated(float x, float y, float z);
	TAfin scaled(float Sx, float Sy, float Sz);
	TAfin rotateX(float angulo);
	TAfin rotateY(float angulo);
	TAfin rotateZ(float angulo);
	TAfin postMultiplica(TAfin);
	TAfin trans();

	GLfloat matriz[16];
};

