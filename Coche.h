#pragma once

#include "SOIL.h"
#include <GL/glu.h>
#include "ObjetoCompuesto3D.h"
#include "Cilindro.h"
#include "Chasis.h"
#include "Volante.h"
#include "Puerta.h"
#include "Ficha.h"
#include "Cubo.h"
#include "PV3D.h"

class Coche : public ObjetoCompuesto3D {
private:
	GLuint texture[1];

public:
	Coche();
	void girar(float angle);
	void openDoors(int angle);
	void closeDoors(int angle);
	PV3D* vDireccion;
	Chasis* chasis;
	Puerta* puertaIzq;
	Puerta* puertaDrch;
	Volante* volante;
	Ficha** ruedas;
	Cilindro* faro1;
	Cilindro* faro2;
};
