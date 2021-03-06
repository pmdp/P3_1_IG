#pragma once

#include "Objeto3D.h"

class ObjetoCompuesto3D : public Objeto3D
{
protected:
	int _numHijos;
	Objeto3D** hijos;

public:
	ObjetoCompuesto3D();
	~ObjetoCompuesto3D();
	void dibuja();
	void girar(float angle) {}
	void addObjeto(Objeto3D* o);
	Objeto3D* getObjeto(int pos);
};

