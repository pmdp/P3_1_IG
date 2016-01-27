#include "Disco.h"

Disco::Disco(float inner, float outer, float slices, float loops)
{
	_inner  = inner;
	_outer  = outer;
	_slices = slices;
	_loops  = loops;

	_disco = gluNewQuadric();
	gluQuadricDrawStyle(_disco, GLU_FILL);
}

void Disco::dibuja()
{
	glColor3f(color->getR(), color->getG(), color->getB());
	gluDisk(_disco, _inner, _outer, _slices, _loops);
}
