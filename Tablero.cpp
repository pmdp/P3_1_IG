#include "Tablero.h"
#include <iostream>
using namespace std;

Tablero::Tablero(int largo, int alto, int ancho)
{
	_largo = largo;
	_alto  = alto;
	_ancho = ancho;

	_numCubos = _largo * _alto * _ancho;

	for (int i = 0; i < _numCubos; i++)
		addObjeto(new Cubo());
}
