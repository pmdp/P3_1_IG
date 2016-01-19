#ifndef OBJETO3D_H_
#define OBJETO3D_H_

#include "TAfin.h"
#include "Color.h"

class Objeto3D {
protected:
	Color* _color;
private:
	TAfin _mt; // Marco de coordenadas donde se mostrará el objeto

public:
	virtual void dibuja() = 0;
	virtual ~Objeto3D() {}
	TAfin getTAfin() { return _mt; }
};

#endif
