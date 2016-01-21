#include "Autopista.h"

Autopista::Autopista()
{
	int ancho = 5;
	int alto = 1;
	int largo = 100;
	
	this->addObjeto(new Tablero(largo, alto, ancho));
	hijos[0]->mt->traslada(new PV3D(0, 0, -3, 1));
	this->addObjeto(new Tablero(largo, alto, ancho));
	hijos[1]->mt->traslada(new PV3D(0, 0, ancho+2, 1));
}

