#include <GL/gl.h>
#include "ObjetoCompuesto3D.h"

void ObjetoCompuesto3D::dibuja()
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glMultMatrixf(this->getTAfin()._m);
		for (int i = 0; i < _numHijos; i++)
			hijos[i]->dibuja();
	glPopMatrix();
}
