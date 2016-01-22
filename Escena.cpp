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

	float randX;
	float randZ;
	float randTree;
	//rand() % ((highestNumber - lowestNumber) + 1) + lowestNumber
	for(int i = 0; i < 50; i++){
		randX = rand() % ((50 - -50) + 1) -50;
		randZ = rand() % ((50 - -50) + 1) -50;
		randTree = rand() % ((18 - 3) + 1) +3;
		addObjeto(new Tree(randTree));
		hijos[i+7]->mt->traslada(new PV3D(randX,0,randZ,1));
	}
}
