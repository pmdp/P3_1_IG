#include "Cubo.h"
#include <GL/glut.h>

Cubo::Cubo(int numText, GLuint* tex, int numCaraTex)
{
	numTexturas = numText;
	textura = tex;
	numCaraTextura = numCaraTex;

	initCube();
}

Cubo::Cubo()
{
	numTexturas = -1;
	initCube();
}
void Cubo::initCube()
{
	//Crea Malla del Cubo
	numVertices = 8;
	numCaras = 6;
	numNormales = numCaras;

	vertice = new PV3D*[numVertices];
	normal = new PV3D*[numNormales];
	cara = new Cara*[numCaras];

	vertice[0] = new PV3D(0.5, 0.5, 0.5, 1);
	vertice[1] = new PV3D(-0.5, 0.5, 0.5, 1);
	vertice[2] = new PV3D(-0.5, -0.5, 0.5, 1);
	vertice[3] = new PV3D(0.5, -0.5, 0.5, 1);
	vertice[4] = new PV3D(0.5, 0.5, -0.5, 1);
	vertice[5] = new PV3D(-0.5, 0.5, -0.5, 1);
	vertice[6] = new PV3D(-0.5, -0.5, -0.5, 1);
	vertice[7] = new PV3D(0.5, -0.5, -0.5, 1);

	//Cara 1
	VerticeNormal** vn1 = new VerticeNormal*[4];
	vn1[0] = new VerticeNormal(0, 0);
	vn1[1] = new VerticeNormal(1, 0);
	vn1[2] = new VerticeNormal(2, 0);
	vn1[3] = new VerticeNormal(3, 0);
	cara[0] = new Cara(4, vn1);
	PV3D* v1 = CalculoVectorNormalPorNewell(cara[0]); //Newell
	normal[0] = v1;
	//Cara 2
	VerticeNormal** vn2 = new VerticeNormal*[4];
	vn2[0] = new VerticeNormal(7, 1);
	vn2[1] = new VerticeNormal(4, 1);
	vn2[2] = new VerticeNormal(0, 1);
	vn2[3] = new VerticeNormal(3, 1);
	cara[1] = new Cara(4, vn2);
	PV3D* v2 = CalculoVectorNormalPorNewell(cara[1]); //Newell
	normal[1] = v2;
	//Cara 3
	VerticeNormal** vn3 = new VerticeNormal*[4];
	vn3[0] = new VerticeNormal(7, 2);
	vn3[1] = new VerticeNormal(6, 2);
	vn3[2] = new VerticeNormal(5, 2);
	vn3[3] = new VerticeNormal(4, 2);
	cara[2] = new Cara(4, vn3);
	PV3D* v3 = CalculoVectorNormalPorNewell(cara[2]); //Newell
	normal[2] = v3;
	//Cara 4
	VerticeNormal** vn4 = new VerticeNormal*[4];
	vn4[0] = new VerticeNormal(0, 3);
	vn4[1] = new VerticeNormal(4, 3);
	vn4[2] = new VerticeNormal(5, 3);
	vn4[3] = new VerticeNormal(1, 3);
	cara[3] = new Cara(4, vn4);
	PV3D* v4 = CalculoVectorNormalPorNewell(cara[3]); //Newell
	normal[3] = v4;
	//Cara 5
	VerticeNormal** vn5 = new VerticeNormal*[4];
	vn5[0] = new VerticeNormal(2, 4);
	vn5[1] = new VerticeNormal(1, 4);
	vn5[2] = new VerticeNormal(5, 4);
	vn5[3] = new VerticeNormal(6, 4);
	cara[4] = new Cara(4, vn5);
	PV3D* v5 = CalculoVectorNormalPorNewell(cara[4]); //Newell
	normal[4] = v5;
	//Cara 6
	VerticeNormal** vn6 = new VerticeNormal*[4];
	vn6[0] = new VerticeNormal(3, 5);
	vn6[1] = new VerticeNormal(7, 5);
	vn6[2] = new VerticeNormal(6, 5);
	vn6[3] = new VerticeNormal(2, 5);
	cara[5] = new Cara(4, vn6);
	PV3D* v6 = CalculoVectorNormalPorNewell(cara[5]); //Newell
	normal[5] = v6;
}
