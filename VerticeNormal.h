#pragma once

#include <GL/gl.h>
#include <GL/glu.h>

class VerticeNormal {
private:
	int _indiceVertice, _indiceNormal;

public:
	VerticeNormal(int indiceVertice, int indiceNormal) : _indiceVertice(indiceVertice), _indiceNormal(indiceNormal)  {}
	int getIndiceNormal()  { return _indiceNormal; }
	int getIndiceVertice() { return _indiceVertice; }
};
