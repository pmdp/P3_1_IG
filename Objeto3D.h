#ifndef OBJETO3D_H_
#define OBJETO3D_H_

#include "TAfin.h"
#include "Color.h"

#include <iostream>
using namespace std;

class Objeto3D {
protected:
	Color* color;

public:
	TAfin* mt;
	Objeto3D(TAfin* matriz) : mt(matriz) {}
	virtual ~Objeto3D() { delete mt; }

	virtual void dibuja() = 0;
};

#endif
