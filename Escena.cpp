#include "Escena.h"

Escena::Escena() 
{
	addObjeto(new Autopista());
	addObjeto(new Coche());
	addObjeto(new Farola());
	hijos[2]->mt->traslada(new PV3D(0,0,5,1));
	addObjeto(new Farola());
	hijos[3]->mt->traslada(new PV3D(20,0,5,1));
	addObjeto(new Farola());
	hijos[4]->mt->traslada(new PV3D(-20,0,5,1));
	addObjeto(new Farola());
	hijos[5]->mt->traslada(new PV3D(-40,0,5,1));
	addObjeto(new Farola());
	hijos[6]->mt->traslada(new PV3D(40,0,5,1));
}
