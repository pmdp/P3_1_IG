#include "Ficha.h"
#include <cmath>

Ficha::Ficha()
{
	_numQuesitos = 6;

	for (int i = 0; i < _numQuesitos; i++) 
		addObjeto(new Quesito(6, 3, 3));
	
	GLfloat inc = 3.14f / 0.33f;
	for (int i = 0; i < _numQuesitos; i++) {
		hijos[i]->mt->traslada(new PV3D(0.05f*cos(i*inc), 0, 0.05f*sin(i*inc), 1));
		hijos[i]->mt->rota(i*60, 0, 1, 0);
	}
}
