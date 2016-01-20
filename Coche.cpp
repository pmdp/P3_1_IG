#include "Coche.h"
#include "PV3D.h"
#include <iostream>
using namespace std;

Coche::Coche() 
: ObjetoCompuesto3D(new TAfin()) 
{
	// RUEDAS ------------------------
	_numRuedas = 4;

	for(int i = 0; i < _numRuedas; i++)
		addObjeto(new Ficha());
		
	// CHASIS ------------------------
	addObjeto(new Cubo());
}

