#ifndef OBJETO3D_H_
#define OBJETO3D_H_

#include "TAfin.h"
#include "Color.h"

#include <iostream>
using namespace std;

class Objeto3D {
public:
	Objeto3D();
	virtual ~Objeto3D();
	virtual void dibuja() = 0;
	virtual void girar(float angle) {}
	Color* color;
	TAfin* mt;
};

#endif
