#pragma once

#include "ObjetoCompuesto3D.h"
#include "Autopista.h"
#include "Farola.h"
#include "Coche.h"
#include "Tree.h"

class Escena : public ObjetoCompuesto3D {
public:
	Escena(GLfloat escenaSize);
	Cubo* ground;
	Coche* coche;
	Autopista* autopista;
	int numFarolas;
	Farola** farolas;
	int numTrees;
	Tree** trees;
	GLfloat escenaSize;
};
