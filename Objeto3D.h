#pragma once

#include "TAfin.h"
#include "Color.h"

class Objeto3D {
protected:
	Color* _color;

public:
	Objeto3D();
	virtual ~Objeto3D();

	virtual void dibuja();
	void setTransAfin(TAfin tAfin);

	TAfin _tAfin; // Marco de coordenadas donde se mostrará el objeto
};

