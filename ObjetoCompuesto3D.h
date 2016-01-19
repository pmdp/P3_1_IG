#pragma once

#include <vector>
#include "Objeto3D.h"

class ObjetoCompuesto3D : public Objeto3D
{
protected:
	//int _numHijos;
	std::vector<Objeto3D*> hijos;

public:
	void dibuja();
	void addObjeto(Objeto3D* o);
};

