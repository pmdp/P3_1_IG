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
	glColor3f(_color->getR(), _color->getG(), _color->getB());
	gluSphere(_esfera, _radio, _slices, _stacks);
}
