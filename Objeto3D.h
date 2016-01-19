#ifndef OBJETO3D_H_
#define OBJETO3D_H_

#include "TAfin.h"
#include "Color.h"

#include <iostream>
using namespace std;

class Objeto3D {
protected:
	Color* _color;
private:
	TAfin* _mt; // Marco de coordenadas donde se mostrará el objeto

public:
	Objeto3D() { _mt = new TAfin(); }
	virtual ~Objeto3D() { delete _mt; }
	virtual void dibuja() = 0;
	TAfin* getTAfin() { return _mt; }
};

#endif
