#pragma once

#include "ObjetoCompuesto3D.h"
#include "Quesito.h"

class Ficha : public ObjetoCompuesto3D
{
	Quesito* _quesito;
	int _numQuesitos;

public:
	Ficha(int numQuesitos);
	virtual void dibuja();
};

