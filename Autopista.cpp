#include "Autopista.h"
#include "Escena.h"

Autopista::Autopista(GLfloat escenaSize)
{
	int ancho = 10;
	int alto = 1;
	GLfloat largo = escenaSize;
	
	this->addObjeto(new Tablero(largo, alto, ancho));
	hijos[0]->mt->traslada(new PV3D(0, -0.2, -ancho-2, 1));
	this->addObjeto(new Tablero(largo, alto, ancho));
	hijos[1]->mt->traslada(new PV3D(0, -0.2, ancho+2, 1));

}

