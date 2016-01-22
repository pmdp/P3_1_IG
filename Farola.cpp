#include "Farola.h"

Farola::Farola()
{
	float altura = 10;

	addObjeto(new Cilindro(0.25, 0.25, altura, 10, 10));
	hijos[0]->color->setColor(0, 0.1, 0.6);
	hijos[0]->mt->rota(-90, 1, 0, 0);

    addObjeto(new Esfera(1, 15, 15));
	hijos[1]->color->setColor(0.5, 0.5, 0);
	hijos[1]->mt->traslada(new PV3D(0, altura, 0, 1));
}
