#include "Autopista.h"
#include "Escena.h"
#include "DiscoParcial.h"

Autopista::Autopista(GLfloat escenaSize)
{
	int ancho = 10;
	int alto = 1;
	GLfloat largo = escenaSize;
	
	this->addObjeto(new Tablero(largo, alto, ancho));
	hijos[0]->mt->traslada(new PV3D(0, -0.2, -ancho-2, 1));
	this->addObjeto(new Tablero(largo, alto, ancho));
	hijos[1]->mt->traslada(new PV3D(0, -0.2, ancho+2, 1));

	// Add curves to the road
	this->addObjeto(new DiscoParcial(7, 17.5, 20, 20, 0, 180));
	hijos[2]->color->setColor(0.2f, 0.2f, 0.2f);
	hijos[2]->mt->traslada(new PV3D(largo/2,0.4,5.5,1));
	hijos[2]->mt->rota(-90, 1, 0, 0);

	this->addObjeto(new DiscoParcial(7, 17.5, 20, 20, 0, 180));
	hijos[3]->color->setColor(0.2f, 0.2f, 0.2f);
	hijos[3]->mt->traslada(new PV3D(-largo/2 + 2,0.4,5.5,1));
	hijos[3]->mt->rota(180,0,1,0);
	hijos[3]->mt->rota(-90, 1, 0, 0);

}

