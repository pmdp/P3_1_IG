#include "Esfera.h"

Esfera::Esfera(float radio, float slices, float stacks)
{
	_radio = radio;
	_slices = slices;
	_stacks = stacks;

	_esfera = gluNewQuadric();
	gluQuadricDrawStyle(_esfera, GLU_FILL);
}

void Esfera::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glMultMatrixf(this->mt->m);
		glColor3f(color->getR(), color->getG(), color->getB());
		gluSphere(_esfera, _radio, _slices, _stacks);
	glPopMatrix();
}
