#pragma once

#include "ObjetoCompuesto3D.h"
#include "Cilindro.h"

class Tree : public ObjetoCompuesto3D {
public:
	Tree(float height);
	bool caido;
};

