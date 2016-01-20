#include "Escena.h"

Escena::Escena() 
: ObjetoCompuesto3D(new TAfin())
{
	// Cuadricula
	// 2 Tableros Carretera
	// Farolas
	addObjeto(new Coche());
}

