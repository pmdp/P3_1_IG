#pragma once

#include "ObjetoCompuesto3D.h"
#include "Quesito.h"

class Ficha : public ObjetoCompuesto3D
{
private:
	int _numQuesitos;
	//ObjetoCompuesto3D* _fichas;

public:
	Ficha();
	//void dibuja();
};

