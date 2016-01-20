#include "Objeto3D.h"

Objeto3D::Objeto3D()
{
	mt = new TAfin();
	color = new Color();
}

Objeto3D::~Objeto3D() 
{
	delete mt;
}
