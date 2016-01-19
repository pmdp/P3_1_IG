#pragma once

#include "ObjetoCompuesto3D.h"
#include "Quesito.h"

class Ficha : public ObjetoCompuesto3D
{
private:
	Quesito** _quesito;
	int _numQuesitos;

public:
	Ficha();
	void dibuja();
};

