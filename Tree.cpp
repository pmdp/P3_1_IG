#include "Tree.h"

Tree::Tree(float height) 
{
	caido = false;
	//Adds trunk
	addObjeto(new Cilindro(height/(height+6), height/(height+6), height, 10, 10));
	hijos[0]->mt->rota(-90, 1, 0, 0);
	hijos[0]->color->setColor(0.5,0.25,0);

	//Adds cones as leafs
	addObjeto(new Cilindro(height/5,0.001,height/2.5,10,10));
	hijos[1]->color->setColor(0,0.4,0.1);
	hijos[1]->mt->traslada(new PV3D(0,height/1.2,0,1));
	hijos[1]->mt->rota(-90, 1, 0, 0);

	addObjeto(new Cilindro(height/4.3,height/13,height/3,10,10));
	hijos[2]->color->setColor(0,0.4,0.1);
	hijos[2]->mt->traslada(new PV3D(0,height/1.8,0,1));
	hijos[2]->mt->rota(-90, 1, 0, 0);

	addObjeto(new Cilindro(height/4,height/8,height/2,10,10));
	hijos[3]->color->setColor(0,0.4,0.1);
	hijos[3]->mt->traslada(new PV3D(0,height/5,0,1));
	hijos[3]->mt->rota(-90, 1, 0, 0);
}

