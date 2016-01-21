#include "Coche.h"
#include "Cubo.h"
#include "Ficha.h"
#include "PV3D.h"

Coche::Coche() 
{
	// RUEDAS ------------------------
	// Delantera izquierda
	addObjeto(new Ficha());
	hijos[0]->mt->traslada(new PV3D(-1, 0, 1, 1));
	hijos[0]->mt->rota(90, 1, 0, 0);

	// Trasera izquierda
	addObjeto(new Ficha());	
	hijos[1]->mt->traslada(new PV3D(1, 0, 1, 1));
	hijos[1]->mt->rota(90, 1, 0, 0);

	// Delantera derecha
	addObjeto(new Ficha());	
	hijos[2]->mt->traslada(new PV3D(-1, 0, -1, 1));
	hijos[2]->mt->rota(90, 1, 0, 0);

	//Trasera derecha
	addObjeto(new Ficha());	
	hijos[3]->mt->traslada(new PV3D(1, 0, -1, 1));
	hijos[3]->mt->rota(90, 1, 0, 0);
	
	// CHASIS ------------------------
	addObjeto(new Cubo());
	hijos[4]->mt->escala(new PV3D(2, 2, 2, 1));
	hijos[4]->mt->traslada(new PV3D(0, 0.5, 0, 1));
	hijos[4]->color->setColor(1, 0, 0);
}

