#include "Escena.h"
#include <iostream>

Escena::Escena() {
	_autopista = new Autopista();
	_coche     = new Coche();
	//_farolas   = new Farola*[2];

	this->addObjeto(_autopista);
}

void Escena::dibuja()
{
	_autopista->dibuja();
	_coche->dibuja();
	//_farolas[0]->dibuja();
	//_farolas[1]->dibuja();
}
