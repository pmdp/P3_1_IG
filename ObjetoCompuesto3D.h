#pragma once

#include <list>
#include "Objeto3D.h"

class ObjetoCompuesto3D : public Objeto3D
{
private:
	std::list<Objeto3D*> _listaObjetos;

public:
    ObjetoCompuesto3D();
	virtual void dibuja();
	void anadirObjeto(Objeto3D* objeto);
};

