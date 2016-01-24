#ifndef MALLA_H_
#define MALLA_H_

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
	GLuint* texturas;
	int numTexturas;
	int numCaraTextura;

public:
	~Malla();
	void dibuja();
	virtual void girar(float angle) {}
	void glGenTextures(unsigned int size, GLuint* texturas);
	void glDeleteTextures(unsigned int size, GLuint* texturas); 
	PV3D* CalculoVectorNormalPorNewell(Cara *c);
};

#endif
