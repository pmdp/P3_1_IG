#pragma once

#include <GL/gl.h>
#include <GL/glu.h>

#include "PV3D.h"
#include "Cara.h"
#include "Objeto3D.h"

class Malla : public Objeto3D {
protected:
	int numVertices;
	PV3D** vertice;
	int numNormales;
	PV3D** normal;
	int numCaras;
	Cara** cara;

public:
	virtual void dibuja();
	PV3D* CalculoVectorNormalPorNewell(Cara *c);
};
