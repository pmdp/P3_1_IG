#pragma once
#include <GL/gl.h>
#include "ObjetoCuadrico.h"

class DiscoParcial : public ObjetoCuadrico {
private:
	GLUquadricObj* _discoParcial;
	GLfloat _inner;
	GLfloat _outer;
	GLint _slices;
	GLint _loops;
	GLdouble _start;
	GLdouble _sweep;

public:
	DiscoParcial(GLfloat inner, GLfloat outer, GLint slices, GLint loops, GLdouble start, GLdouble sweep);
	void dibuja();
};
