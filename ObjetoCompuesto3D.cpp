#include <GL/gl.h>
#include "ObjetoCompuesto3D.h"
#include <iostream>

void ObjetoCompuesto3D::dibuja()
{
	std::cout << "ObjetoCompuesto3D::dibuja" << std::endl;
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		std::vector<Objeto3D*>::iterator it = hijos.begin();
		glMultMatrixf(this->getTAfin()->m);
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
Objeto3D* ObjetoCompuesto3D::getObjetoAt(int pos)
{
	return hijos[pos];
}
