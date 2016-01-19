#include "Ficha.h"
#include <iostream>
#include <cmath>
using namespace std;

Ficha::Ficha()
{
	_numQuesitos = 6;
	_quesito = new Quesito*[_numQuesitos];

	for (int i = 0; i < _numQuesitos; i++)
		_quesito[i] = new Quesito(57, 6, 4);

	//Se sitúan los quesitos dentro de la ficha
	GLfloat inc = 3.14f / 0.33f;
	for (int i = 0; i < _numQuesitos; i++) {
		hijos[i]->getTAfin().translada(new PV3D(0.05f*cos(i*inc), 0, 0.05f*sin(i*inc), 1));
		hijos[i]->getTAfin().rota(i*60, 0, 1, 0);
	}
}

void Ficha::dibuja()
{
	for (int i = 0; i <= _numQuesitos; i++) {
		if      (i == 0) glColor3f(1.f, 0.f, 0.f);
		else if (i == 1) glColor3f(0.f, 1.f, 0.f);
		else if (i == 2) glColor3f(0.f, 0.f, 1.f);
		else if (i == 3) glColor3f(1.f, 1.f, 0.f);
		else if (i == 4) glColor3f(1.f, 0.f, 1.f);
		else if (i == 5) glColor3f(0.f, 1.f, 1.f);
		
		glPushMatrix();
		glRotatef(60 * i, 0.f, 1.f, 0.f);
		_quesito[i]->dibuja();
		glPopMatrix();
	}
}
