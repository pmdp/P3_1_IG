#include "Tablero.h"

Tablero::Tablero(int largo, int alto, int ancho) 
{
	_largo = largo;
	_alto = alto;
	_ancho = ancho;

	_numCubos = _largo * _alto * _ancho;

	for (int i = 0; i < _numCubos; i++) {
		this->addObjeto(new Cubo());
		hijos[i]->color->setColor(0.2, 0.2, 0.2);
	}

	//comienza pintando al principio de la carretara
	PV3D* p = new PV3D(_largo / 2, 0, 1, 1);

	int numCubo = 0;
	for (int x = 0; x < _largo; x++) {
		for (int y = 0; y < _alto; y++) {
			for (int z = 0; z < _ancho; z++) {
				hijos[numCubo]->mt->traslada(p);
				p->setZ(p->getZ()+1);
				numCubo++;
			}
			p->setZ(p->getZ()-_ancho);
			if(_alto > 1)
				p->setY(p->getY()+1);
		}
		if(_alto > 1)
			p->setY(p->getY()-_alto);
		p->setX(p->getX()-1);
	}
}
