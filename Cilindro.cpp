#include "Cilindro.h"

Cilindro::Cilindro(float radio1, float radio2, float alto, float slices, float stacks)
{
	_radio1 = radio1;
	_radio2 = radio2;
	_alto   = alto;
	_slices = slices;
	_stacks = stacks;

	_cilindro = gluNewQuadric();
	gluQuadricDrawStyle(_cilindro, GLU_FILL);
}

void Cilindro::dibuja()
{
	glColor3f(_color->getR(), _color->getG(), _color->getB());
	gluCylinder(_cilindro, _radio1, _radio2, _alto, _slices, _stacks);
}
