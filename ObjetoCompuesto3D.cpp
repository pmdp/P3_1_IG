#include <GL/gl.h>
#include "ObjetoCompuesto3D.h"

ObjetoCompuesto3D::ObjetoCompuesto3D()
{
	_numHijos = 0;
	hijos = new Objeto3D*[50];
}

void ObjetoCompuesto3D::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glMultMatrixf(this->mt->m);
		for(int i = 0; i < _numHijos; i++)
			hijos[i]->dibuja();
	glPopMatrix();
}

void ObjetoCompuesto3D::addObjeto(Objeto3D* o)
{
	hijos[_numHijos] = o;
	_numHijos++;
}
