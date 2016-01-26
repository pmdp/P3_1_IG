#pragma once
#include <GL/gl.h>
#include <GL/glu.h>

#include <GL/freeglut.h>
#include "VerticeNormal.h"

class Cara {
private:
	int _numVertices;
	VerticeNormal** arrayVN;
public:
	Cara(int numVertices, VerticeNormal **vn) : _numVertices(numVertices), arrayVN(vn)  {}
	~Cara();

	int getNumVertices() { return _numVertices; }
	int getIndiceVertice(int index) { return arrayVN[index]->getIndiceVertice(); }
	int getIndiceNormal(int index)  { return arrayVN[index]->getIndiceNormal(); }
};
