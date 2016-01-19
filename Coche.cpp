#include "Coche.h"

Coche::Coche() {
	
	// RUEDAS ------------------------
	_numRuedas = 4;
	_coche = new ObjetoCompuesto3D();

	//_ruedas = new Quesito*[_numRuedas];
	//_ruedas[0] = new Quesito(6, 3, 3);
	//_ruedas[1] = new Quesito(6, 3, 3);
	//_ruedas[2] = new Quesito(6, 3, 3);
	//_ruedas[3] = new Quesito(6, 3, 3);

	//for(int i = 0; i < _numRuedas; i++)
		//_coche->addObjeto(_ruedas[i]);
	
	// CHASIS ------------------------
	_chasis = new Cubo();
	_coche->addObjeto(_chasis);
}

void Coche::dibuja()
{
	_coche->dibuja();
}
