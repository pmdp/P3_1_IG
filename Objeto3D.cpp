#include "Objeto3D.h"

Objeto3D::Objeto3D()
{
	mt = new TAfin();
}

Objeto3D::~Objeto3D() 
{
	delete mt;
}
