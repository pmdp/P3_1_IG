#include "DiscoParcial.h"
#include "Autopista.h"
#include "Escena.h"

Autopista::Autopista(GLfloat escenaSize)
{
	float ancho = 10;
	float alto = 1;
	GLfloat largo = escenaSize;
	
	// Add the road
	this->addObjeto(new Tablero(largo, alto, ancho));
	hijos[0]->mt->traslada(new PV3D(0, -0.2, -ancho-2.5, 1));
	this->addObjeto(new Tablero(largo, alto, ancho));
	hijos[1]->mt->traslada(new PV3D(0, -0.2, ancho+2, 1));

	// Add curves to the road
	this->addObjeto(new DiscoParcial(7, 17.5, 20, 20, 0, 180));
	hijos[2]->color->setColor(0.2f, 0.2f, 0.2f);
	//hijos[2]->mt->rota(-90, 1, 0, 0);
}

