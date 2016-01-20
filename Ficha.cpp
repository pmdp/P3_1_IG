#include "Ficha.h"
#include <iostream>
#include <cmath>
using namespace std;

Ficha::Ficha()
{
	_numQuesitos = 6;

	for (int i = 0; i < _numQuesitos; i++)
		addObjeto(new Quesito(6, 3, 3));

	GLfloat inc = 3.14f / 0.33f;
	for (int i = 0; i < _numQuesitos; i++) {
		hijos[i]->getTAfin()->translada(new PV3D(0.05f*cos(i*inc), 0, 0.05f*sin(i*inc), 1));
		hijos[i]->getTAfin()->rota(i*60, 0, 1, 0);
	}
	cout << "Constr ficha" << endl;
}

//void Ficha::dibuja()
//{
	//cout << "Ficha" << endl;
	//ObjetoCompuesto3D::dibuja();
	//for (int i = 0; i < _numQuesitos; i++) 
	//{
		//if      (i == 0) glColor3f(1.f, 0.f, 0.f);
		//else if (i == 1) glColor3f(0.f, 1.f, 0.f);
		//else if (i == 2) glColor3f(0.f, 0.f, 1.f);
		//else if (i == 3) glColor3f(1.f, 1.f, 0.f);
		//else if (i == 4) glColor3f(1.f, 0.f, 1.f);
		//else if (i == 5) glColor3f(0.f, 1.f, 1.f);
		
		//glPushMatrix();
		//glRotatef(60 * i, 0.f, 1.f, 0.f);
		//hijos[i]->dibuja();		
		//glPopMatrix();
	//}
//}
