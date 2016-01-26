/*
 * Puerta.cpp
 *
 *  Created on: Jan 26, 2016
 *      Author: pepc
 */

#include "Puerta.h"

Puerta::Puerta() {
	//Crea Malla del Cubo
		numVertices = 5;
		numCaras = 1;
		numNormales = numCaras;

		vertice = new PV3D*[numVertices];
		normal = new PV3D*[numNormales];
		cara = new Cara*[numCaras];

		vertice[0] = new PV3D(0.0, 0.0, 0.0, 1);
		vertice[1] = new PV3D(6.0, 0.0, 0.0, 1);
		vertice[2] = new PV3D(6.0, 6.0, 0.5, 1);
		vertice[3] = new PV3D(2.0, 6.0, 0.5, 1);
		vertice[4] = new PV3D(0.0, 3.0, 0.5, 1);

		//Cara 1
		VerticeNormal** vn1 = new VerticeNormal*[5];
		vn1[0] = new VerticeNormal(0, 0);
		vn1[1] = new VerticeNormal(1, 0);
		vn1[2] = new VerticeNormal(2, 0);
		vn1[3] = new VerticeNormal(3, 0);
		vn1[4] = new VerticeNormal(4, 0);
		cara[0] = new Cara(5, vn1);
		PV3D* v1 = CalculoVectorNormalPorNewell(cara[0]); //Newell
		normal[0] = v1;

}

Puerta::~Puerta() {
	// TODO Auto-generated destructor stub
}

