#include "Coche.h"
#include "Cubo.h"
#include "Ficha.h"
#include "PV3D.h"

Coche::Coche() 
{
	vDireccion = new PV3D(-1,0,0,0);
	// RUEDAS -------------------------------------------
	// Delantera izquierda
	addObjeto(new Ficha());
	hijos[0]->mt->traslada(new PV3D(-1, 1, 1, 1));
	hijos[0]->mt->rota(90, 1, 0, 0);

	// Trasera izquierda
	addObjeto(new Ficha());	
	hijos[1]->mt->traslada(new PV3D(1, 1, 1, 1));
	hijos[1]->mt->rota(90, 1, 0, 0);

	// Delantera derecha
	addObjeto(new Ficha());	
	hijos[2]->mt->traslada(new PV3D(-1, 1, -1, 1));
	hijos[2]->mt->rota(-90, 1, 0, 0);

	//Trasera derecha
	addObjeto(new Ficha());	
	hijos[3]->mt->traslada(new PV3D(1, 1, -1, 1));
	hijos[3]->mt->rota(-90, 1, 0, 0);
	// ---------------------------------------------------

	// CHASIS --------------------------------------------
	addObjeto(new Cubo());
	hijos[4]->mt->escala(new PV3D(4, 2, 2, 1));
	hijos[4]->mt->traslada(new PV3D(0, 1, 0, 1));
	hijos[4]->color->setColor(1, 0, 0);

	addObjeto(new Cubo());
	hijos[5]->mt->escala(new PV3D(2, 2, 2, 1));
	hijos[5]->mt->traslada(new PV3D(0.5, 2, 0, 1));
	hijos[5]->color->setColor(1, 0, 0);

	// ---------------------------------------------------

	faro1 = new Cilindro(0.09,0.4,0.5,10,10);
	addObjeto(faro1);
	faro1->mt->traslada(new PV3D(-2,1.5,0.7,1));
	faro1->mt->rota(-90,0,1,0);
	faro1->color->setColor(0.5,0.5,0);
	faro2 = new Cilindro(0.09,0.4,0.5,10,10);
	addObjeto(faro2);
	faro2->mt->traslada(new PV3D(-2,1.5,-0.7,1));
	faro2->mt->rota(-90,0,1,0);
	faro2->color->setColor(0.5,0.5,0);


}

void Coche::girar(float angle) 
{
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			hijos[i]->mt->rota(angle, 0, 1, 0);
		else
			hijos[i]->mt->rota(-angle, 0, 1, 0);
	}
}

