#include "Tablero.h"

Tablero::Tablero(int largo, int alto, int ancho)
{
	_largo = largo;
	_alto  = alto;
	_ancho = ancho;

	_numCubos = _largo * _alto * _ancho;
	_cubos = new Cubo*[_numCubos];
}

void Tablero::dibuja()
{

}
