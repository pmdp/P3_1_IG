#include "Tablero.h"
#include <iostream>
using namespace std;

Tablero::Tablero(int largo, int alto, int ancho)
{
	_largo = largo;
	_alto  = alto;
	_ancho = ancho;

	_numCubos = _largo * _alto * _ancho;
	_cubos = new Cubo*[_numCubos];

	for (int i = 0; i < _numCubos; i++)
		_cubos[i] = new Cubo();
}

void Tablero::dibuja()
{
	for(int i = 0; i < _numCubos; i++)
		_cubos[i]->dibuja();
}
