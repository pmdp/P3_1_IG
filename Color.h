#pragma once

class Color {
private:
	float _r;
	float _g;
	float _b;

public:
	Color() : _r(0), _g(0), _b(0) {}
	float getR() { return _r; }
	float getG() { return _g; }
	float getB() { return _b; }

	void setR(float r) { _r = r; }
	void setG(float g) { _g = g; }
	void setB(float b) { _b = b; }
};
