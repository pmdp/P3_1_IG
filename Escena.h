#pragma once

#include <list>

#include "ObjetoCompuesto3D.h"
#include "Autopista.h"
#include "Farola.h"
#include "Coche.h"

class Escena : public ObjetoCompuesto3D {
private:
	Autopista _autopista;
	Coche 	  _coche;
	std::list<Farola*> _farolas;

public:
	Escena();
	virtual void dibuja();
};
