#include <GL/gl.h>
#include "ObjetoCompuesto3D.h"

void ObjetoCompuesto3D::dibuja()
{
		std::vector<Objeto3D*>::iterator it = hijos.begin();
		while (it != hijos.end()) 
		{
			glMatrixMode(GL_MODELVIEW);
			glPushMatrix();
				glMultMatrixf(this->mt->m);
				Objeto3D* object = *it;
				object->dibuja();
				it++;
			glPopMatrix();
		}
}

void ObjetoCompuesto3D::addObjeto(Objeto3D* o)
{
	hijos.push_back(o);
}
