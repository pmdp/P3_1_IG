#include "Malla.h"
#include <iostream>
using namespace std;

void Malla::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glMultMatrixf(mt->m);

		for (int i = 0; i < numCaras; i++) 
		{	
			glLineWidth(1.0);
			glBegin(GL_POLYGON);
			
				glBindTexture(GL_TEXTURE_2D, texturas[0]);
		
				for (int j = 0; j < cara[i]->getNumVertices(); j++)	
				{
					int iN = cara[i]->getIndiceNormal(j);
					int	iV = cara[i]->getIndiceVertice(j);

					if (numTexturas != -1) {
						cout << "Si textura" << endl;

						if (j == 0)
							glTexCoord2i(0,0); 
						if (j == 1)
							glTexCoord2i(0,1); 
						if (j == 2)
							glTexCoord2i(1,1); 
						if (j == 3)
							glTexCoord2i(1,0); 
					} else {
						glColor3f(color->getR(), color->getG(), color->getB());
					}

					glNormal3f(normal[iN]->getX(), normal[iN]->getY(), normal[iN]->getZ());
					glVertex3f(vertice[iV]->getX(), vertice[iV]->getY(), vertice[iV]->getZ());
				}
			glEnd();
		}

	glPopMatrix();
}

PV3D* Malla::CalculoVectorNormalPorNewell(Cara *c) 
{
	PV3D *vertActual	= new PV3D(0.0f, 0.0f, 0.0f, 1);
	PV3D *vertSiguiente = new PV3D(0.0f, 0.0f, 0.0f, 1);

	GLdouble x = 0, y = 0, z = 0;

	for (int i = 0; i < c->getNumVertices(); i++)
	{
		vertActual = vertice[c->getIndiceVertice(i)];
		int index = (c->getIndiceVertice((i + 1) % c->getNumVertices()));

		vertSiguiente = vertice[index];
		x += (vertActual->getY() - vertSiguiente->getY()) * (vertActual->getZ() + vertSiguiente->getZ());
		y += (vertActual->getZ() - vertSiguiente->getZ()) * (vertActual->getX() + vertSiguiente->getX());
		z += (vertActual->getX() - vertSiguiente->getX()) * (vertActual->getY() + vertSiguiente->getY());		
	}
	PV3D* n = new PV3D(x, y, z, 1);

	n->normaliza();
	return n;
}

Malla::~Malla()
{
	for (int i = 0; i < numVertices; i++)
		delete vertice[i];
	delete[] vertice;

	for (int i = 0; i < numNormales; i++)
		delete normal[i];
	delete[] normal;

	for (int i = 0; i < numCaras; i++)
		delete cara[i];
	delete[] cara;
}

