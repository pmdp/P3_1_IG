#include <GL/gl.h>
#include "ObjetoCompuesto3D.h"

void ObjetoCompuesto3D::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		std::vector<Objeto3D*>::iterator it = hijos.begin();
		while (it != hijos.end()) 
		{
			Objeto3D* object = *it;
			glMultMatrixf(object->getTAfin()._m);
			object->dibuja();
			it++;
		}
	glPopMatrix();
}

void ObjetoCompuesto3D::addObjeto(Objeto3D* o)
{
	hijos.push_back(o);
}
