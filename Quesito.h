#pragma once
#include "Malla.h"

class Quesito : public Malla
{
private:
	int _nq; 	 //Numero de veces q se divide la parte circular
	int _radio;  //Radio
	int _altura; //Altura

public:
	Quesito(int nq, int r, int a);
};

