#include "DiscoParcial.h"

DiscoParcial::DiscoParcial(GLfloat inner, GLfloat outer, GLint slices, GLint loops, GLdouble start, GLdouble sweep)
{
	_inner  = inner;
	_outer  = outer;
	_slices = slices;
	_loops  = loops;
	_start  = start;
	_sweep  = sweep;

	_discoParcial = gluNewQuadric();
	gluQuadricDrawStyle(_discoParcial, GLU_FILL);
}

void DiscoParcial::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glMultMatrixf(this->mt->m);
		glColor3f(color->getR(), color->getG(), color->getB());
		//glColor3f(0.2, 0.2, 0.2);
		//glRotated(90, 1.0, 0.0, 0.0);
		//glTranslatef(1.0f, 5.5f, -0.31f);
		gluPartialDisk(_discoParcial, _inner, _outer, _slices, _loops, _start, _sweep);
	glPopMatrix();
}



