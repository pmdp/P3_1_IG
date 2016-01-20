#include "Coche.h"
#include "PV3D.h"
#include <iostream>
using namespace std;

Coche::Coche() 
{
	// RUEDAS ------------------------
	_numRuedas = 4;
	//_coche = new ObjetoCompuesto3D();

	addObjeto(new Ficha());
	//_rueda2 = new Ficha();
	//_rueda3 = new Ficha();
	//_rueda4 = new Ficha();
	
	//_coche->addObjeto(new Ficha());
	//_coche->addObjeto(_rueda2);
	//_coche->addObjeto(_rueda3);
	//_coche->addObjeto(_rueda4);
	// CHASIS ------------------------
	
	addObjeto(new Cubo());
	//_coche->addObjeto(new Cubo());
	//_coche->getObjetoAt(1)->getTAfin()->translada(new PV3D(4, 0, 0, 1));
cout << "Coche constru" << endl;
}

//void Coche::dibuja()
//{
	//cout << "Coche dibuja" << endl;
	//ObjetoCompuesto3D::dibuja();	
//}
