#pragma once

#include <vector>
#include "Objeto3D.h"

class ObjetoCompuesto3D : public Objeto3D
{
protected:
	std::vector<Objeto3D*> hijos;

public:
	ObjetoCompuesto3D(TAfin* mt) : Objeto3D(mt) {};
	void dibuja();
	void addObjeto(Objeto3D* o);
};

