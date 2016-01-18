#include "Objeto3D.h"

Objeto3D::Objeto3D()
{
	_color = new Color();
}

void Objeto3D::setTransAfin(TAfin tAfin)
{
	for (int i = 0; i < 16; i++)
		_tAfin.matriz[i] = tAfin.matriz[i];
}
