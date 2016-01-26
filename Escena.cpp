#include "Escena.h"

Escena::Escena(GLfloat escenaSiz)
{
	escenaSize = escenaSiz;
	ground = new Cubo();
	ground->mt->escala(new PV3D(escenaSize,1,escenaSize,1));
	ground->mt->traslada(new PV3D(0.0,-0.5,0.0,1));
	ground->color->setColor(0,0.2,0.1);
	addObjeto(ground);

	coche = new Coche();
	addObjeto(coche);
	autopista = new Autopista(escenaSize);
	addObjeto(autopista);
	numFarolas = escenaSize/15;
	farolas = new Farola*[numFarolas];

	PV3D* p = new PV3D(-escenaSize/2,0,5,1);
	for (int i=0;i <= numFarolas; i++){
		farolas[i] = new Farola();
		farolas[i]->mt->traslada(p);
		addObjeto(farolas[i]);
		p->setX(p->getX()+ escenaSize/numFarolas);

	}

	float randX;float randZ;float randTree;
	numTrees = escenaSize;
	int range = escenaSize/2;
	trees = new Tree*[numTrees];
	//rand() % ((highestNumber - lowestNumber) + 1) + lowestNumber
	for(int i = 0; i < numTrees; i++){
		randX = rand() % ((range - -range) + 1) -range;
		randZ = rand() % ((range - -range) + 1) -range;
		if(randZ > -15 && randZ < 25)
			i--;
		else{
		randTree = rand() % ((18 - 3) + 1) +3;
		trees[i] = new Tree(randTree);
		addObjeto(trees[i]);
		trees[i]->mt->traslada(new PV3D(randX,0,randZ,1));
		}
	}
}

Escena::~Escena()
{
	delete[] farolas;
	delete[] trees;
}
