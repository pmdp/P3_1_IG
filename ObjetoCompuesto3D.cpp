#include <GL/gl.h>
#include "ObjetoCompuesto3D.h"

ObjetoCompuesto3D::ObjetoCompuesto3D()
{

}

void ObjetoCompuesto3D::dibuja()
{
	std::list<Objeto3D*>::iterator it = _listaObjetos.begin();
	while (it != _listaObjetos.end())
	{
		Objeto3D* objeto = *it;

		glMatrixMode(GL_MODELVIEW);
		glPushMatrix();
		glMultMatrixf(objeto->_tAfin.matriz);
		objeto->dibuja();
		glPopMatrix();
		it++;
	}
}

void ObjetoCompuesto3D::anadirObjeto(Objeto3D* objeto)
{
	_listaObjetos.push_back(objeto);
}
