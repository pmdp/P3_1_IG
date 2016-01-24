#pragma once

#include "SOIL.h"
#include <GL/glu.h>
#include "ObjetoCompuesto3D.h"
#include "Cilindro.h"

class Coche : public ObjetoCompuesto3D {
private:
	GLuint texture[1];

public:
	Coche();
	void girar(float angle);
	void loadTextures();
	PV3D* vDireccion;
	Cilindro* faro1;
	Cilindro* faro2;
};
