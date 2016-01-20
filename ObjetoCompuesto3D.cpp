#include <GL/gl.h>
#include "ObjetoCompuesto3D.h"
#include <iostream>

void ObjetoCompuesto3D::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		std::vector<Objeto3D*>::iterator it = hijos.begin();
		glMultMatrixf(this->mt->m);
		while (it != hijos.end()) 
		{
			Objeto3D* object = *it;
			object->dibuja();
			it++;
		}
	glPopMatrix();
}

void ObjetoCompuesto3D::addObjeto(Objeto3D* o)
{
	hijos.push_back(o);
}
