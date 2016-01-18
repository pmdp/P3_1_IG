#include "Malla.h"
#include <iostream>
using namespace std;

void Malla::dibuja()
{
	for (int i = 0; i < numCaras; i++) {	
		glLineWidth(1.0);
		glBegin(GL_LINE_LOOP);
			for (int j = 0; j < cara[i]->getNumVertices(); j++)	{
				int iN = cara[i]->getIndiceNormal(j);
				int	iV = cara[i]->getIndiceVertice(j);

				glNormal3f(normal[iN]->getX(), normal[iN]->getY(), normal[iN]->getZ());
				glVertex3f(vertice[iV]->getX(), vertice[iV]->getY(), vertice[iV]->getZ());
			}
		glEnd();
	}
}

PV3D* Malla::CalculoVectorNormalPorNewell(Cara *c) {
	
	PV3D *vertActual	= new PV3D(0.0f, 0.0f, 0.0f, 1);
	PV3D *vertSiguiente = new PV3D(0.0f, 0.0f, 0.0f, 1);

	GLdouble x = 0, y = 0, z = 0;

	for (int i = 0; i < c->getNumVertices(); i++)
	{
		vertActual = vertice[c->getIndiceVertice(i)];
		//int asd = c->getIndiceVertice(i + 1);
		//int b = c->getNumVertices();
		//int d = a % b;
		int index = (c->getIndiceVertice((i + 1) % c->getNumVertices()));

		vertSiguiente = vertice[index];
		x += (vertActual->getY() - vertSiguiente->getY()) * (vertActual->getZ() + vertSiguiente->getZ());
		y += (vertActual->getZ() - vertSiguiente->getZ()) * (vertActual->getX() + vertSiguiente->getX());
		z += (vertActual->getX() - vertSiguiente->getX()) * (vertActual->getY() + vertSiguiente->getY());		
	}
	PV3D* n = new PV3D(x, y, z, 1);

	//delete vertActual;
	//delete vertSiguiente;

	n->normaliza();
	return n;
}
