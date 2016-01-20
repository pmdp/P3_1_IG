#include "Coche.h"
#include "Cubo.h"
#include "Ficha.h"
#include "PV3D.h"

Coche::Coche() 
{
	// RUEDAS ------------------------
	addObjeto(new Ficha());
	hijos[0]->mt->traslada(new PV3D(0, 0, 0, 1));
	hijos[0]->mt->rota(90, 1, 0, 0);

	addObjeto(new Ficha());	
	hijos[1]->mt->traslada(new PV3D(12, 0, 0, 1));
	hijos[1]->mt->rota(90, 1, 0, 0);

	addObjeto(new Ficha());	
	hijos[2]->mt->traslada(new PV3D(0, 0, 10, 1));
	hijos[2]->mt->rota(90, 1, 0, 0);

	addObjeto(new Ficha());	
	hijos[3]->mt->traslada(new PV3D(12, 0, 10, 1));
	hijos[3]->mt->rota(90, 1, 0, 0);
	
	// CHASIS ------------------------
	//addObjeto(new Cubo());
}

