#include "Escena.h"
#include <iostream>
using namespace std;

Escena::Escena() {
	ObjetoCompuesto3D::addObjeto(new Coche());
}

//void Escena::dibuja()
//{
	//cout << "Escena::dibuja" << endl;
	//ObjetoCompuesto3D::dibuja();
//}
