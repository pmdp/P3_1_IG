#pragma once

#include <list>
#include "Objeto3D.h"

class ObjetoCompuesto3D : public Objeto3D
{
protected:
	int _numHijos;
	Objeto3D** hijos;

public:
	void dibuja();
};

