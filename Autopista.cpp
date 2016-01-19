#include "Autopista.h"
#include <iostream>
using namespace std;

Autopista::Autopista()
{
	_carretera1 = new Tablero(10, 1, 1);
	//_carretera2 = new Tablero(2, 3, 10);
}

void Autopista::dibuja()
{
	_carretera1->dibuja();
	//_carretera2->dibuja();
}
