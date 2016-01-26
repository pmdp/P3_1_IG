/*
 * Chasis.cpp
 *
 *  Created on: Jan 26, 2016
 *      Author: pepc
 */

#include "Chasis.h"

Chasis::Chasis() {

		//numTexturas=-1;
		//Crea Malla del Chasis
		numVertices = 42;
		numCaras = 27;
		numNormales = numCaras;

		vertice = new PV3D*[numVertices];
		normal = new PV3D*[numNormales];
		cara = new Cara*[numCaras];

		//Vertices
		vertice[0] = new PV3D(-11.0, 0.0, 4.0, 1);
		vertice[1] = new PV3D(-8.0, 0.0, 4.0, 1);
		vertice[2] = new PV3D(-7.5, 1.2, 4.0, 1);
		vertice[3] = new PV3D(-7.5, 3.0, 4.0, 1);
		vertice[4] = new PV3D(-11.0, 3.0, 4.0, 1);
		vertice[5] = new PV3D(-5.5, 1.2, 4.0, 1);
		vertice[6] = new PV3D(-5.5, 3.0, 4.0, 1);
		vertice[7] = new PV3D(-5.0, 0.0, 4.0, 1);
		vertice[8] = new PV3D(-3.0, 0.0, 4.0, 1);
		vertice[9] = new PV3D(-3.0, 3.0, 4.0, 1);
		vertice[10] = new PV3D(3.0, 6.0, 4.0, 1);
		vertice[11] = new PV3D(-1.0, 6.0, 4.0, 1);
		vertice[12] = new PV3D(3.0, 0.0, 4.0, 1);
		vertice[13] = new PV3D(5.0, 0.0, 4.0, 1);
		vertice[14] = new PV3D(5.5, 1.2, 4.0, 1);
		vertice[15] = new PV3D(7.5, 1.2, 4.0, 1);
		vertice[16] = new PV3D(7.5, 3.0, 4.0, 1);
		vertice[17] = new PV3D(6.5, 6.0, 4.0, 1);
		vertice[18] = new PV3D(8.0, 0.0, 4.0, 1);
		vertice[19] = new PV3D(11.0, 0.0, 4.0, 1);
		vertice[20] = new PV3D(11.0, 3.0, 4.0, 1);
		vertice[21] = new PV3D(-11.0, 0.0, -4.0, 1);
		vertice[22] = new PV3D(-11.0, 3.0, -4.0, 1);
		vertice[23] = new PV3D(-7.5, 3.0, -4.0, 1);
		vertice[24] = new PV3D(-7.5, 1.2, -4.0, 1);
		vertice[25] = new PV3D(-8.0, 0.0, -4.0, 1);
		vertice[26] = new PV3D(-5.5, 1.2, -4.0, 1);
		vertice[27] = new PV3D(-5.5, 3.0, -4.0, 1);
		vertice[28] = new PV3D(-5.0, 0.0, -4.0, 1);
		vertice[29] = new PV3D(-3.0, 0.0, -4.0, 1);
		vertice[30] = new PV3D(-3.0, 3.0, -4.0, 1);
		vertice[31] = new PV3D(-1.0, 6.0, -4.0, 1);
		vertice[32] = new PV3D(3.0, 6.0, -4.0, 1);
		vertice[33] = new PV3D(3.0, 0.0, -4.0, 1);
		vertice[34] = new PV3D(5.0, 0.0, -4.0, 1);
		vertice[35] = new PV3D(5.5, 1.2, -4.0, 1);
		vertice[36] = new PV3D(7.5, 1.2, -4.0, 1);
		vertice[37] = new PV3D(7.5, 3.0, -4.0, 1);
		vertice[38] = new PV3D(6.5, 6.0, -4.0, 1);
		vertice[39] = new PV3D(11.0, 3.0, -4.0, 1);
		vertice[40] = new PV3D(11.0, 0.0, -4.0, 1);
		vertice[41] = new PV3D(8.0, 0.0, -4.0, 1);

		//Cara 0
		VerticeNormal** vn0 = new VerticeNormal*[5];
		vn0[0] = new VerticeNormal(0, 0);
		vn0[1] = new VerticeNormal(1, 0);
		vn0[2] = new VerticeNormal(2, 0);
		vn0[3] = new VerticeNormal(3, 0);
		vn0[4] = new VerticeNormal(4, 0);
		cara[0] = new Cara(5, vn0);
		PV3D* v0 = CalculoVectorNormalPorNewell(cara[0]); //Newell
		normal[0] = v0;

		//Cara 1
		VerticeNormal** vn1 = new VerticeNormal*[4];
		vn1[0] = new VerticeNormal(2, 1);
		vn1[1] = new VerticeNormal(5, 1);
		vn1[2] = new VerticeNormal(6, 1);
		vn1[3] = new VerticeNormal(3, 1);
		cara[1] = new Cara(4, vn1);
		PV3D* v1 = CalculoVectorNormalPorNewell(cara[1]); //Newell
		normal[1] = v1;

		//Cara 2
		VerticeNormal** vn2 = new VerticeNormal*[5];
		vn2[0] = new VerticeNormal(5, 2);
		vn2[1] = new VerticeNormal(7, 2);
		vn2[2] = new VerticeNormal(8, 2);
		vn2[3] = new VerticeNormal(9, 2);
		vn2[4] = new VerticeNormal(6, 2);
		cara[2] = new Cara(5, vn2);
		PV3D* v2 = CalculoVectorNormalPorNewell(cara[2]); //Newell
		normal[2] = v2;

		//Cara 3
		VerticeNormal** vn3 = new VerticeNormal*[7];
		vn3[0] = new VerticeNormal(12, 3);
		vn3[1] = new VerticeNormal(13, 3);
		vn3[2] = new VerticeNormal(14, 3);
		vn3[3] = new VerticeNormal(15, 3);
		vn3[4] = new VerticeNormal(16, 3);
		vn3[5] = new VerticeNormal(17, 3);
		vn3[6] = new VerticeNormal(10, 3);
		cara[3] = new Cara(7, vn3);
		PV3D* v3 = CalculoVectorNormalPorNewell(cara[3]); //Newell
		normal[3] = v3;

		//Cara 4
		VerticeNormal** vn4 = new VerticeNormal*[5];
		vn4[0] = new VerticeNormal(15, 4);
		vn4[1] = new VerticeNormal(18, 4);
		vn4[2] = new VerticeNormal(19, 4);
		vn4[3] = new VerticeNormal(20, 4);
		vn4[4] = new VerticeNormal(16, 4);
		cara[4] = new Cara(5, vn4);
		PV3D* v4 = CalculoVectorNormalPorNewell(cara[4]); //Newell
		normal[4] = v4;

		//Cara 5
		VerticeNormal** vn5 = new VerticeNormal*[5];
		vn5[0] = new VerticeNormal(21, 5);
		vn5[1] = new VerticeNormal(22, 5);
		vn5[2] = new VerticeNormal(23, 5);
		vn5[3] = new VerticeNormal(24, 5);
		vn5[4] = new VerticeNormal(25, 5);
		cara[5] = new Cara(5, vn5);
		PV3D* v5 = CalculoVectorNormalPorNewell(cara[5]); //Newell
		normal[5] = v5;

		//Cara 6
		VerticeNormal** vn6 = new VerticeNormal*[4];
		vn6[0] = new VerticeNormal(24, 6);
		vn6[1] = new VerticeNormal(23, 6);
		vn6[2] = new VerticeNormal(27, 6);
		vn6[3] = new VerticeNormal(26, 6);
		cara[6] = new Cara(4, vn6);
		PV3D* v6 = CalculoVectorNormalPorNewell(cara[6]); //Newell
		normal[6] = v6;

		//Cara 7
		VerticeNormal** vn7 = new VerticeNormal*[5];
		vn7[0] = new VerticeNormal(29, 7);
		vn7[1] = new VerticeNormal(28, 7);
		vn7[2] = new VerticeNormal(26, 7);
		vn7[3] = new VerticeNormal(27, 7);
		vn7[4] = new VerticeNormal(30, 7);
		cara[7] = new Cara(5, vn7);
		PV3D* v7 = CalculoVectorNormalPorNewell(cara[7]); //Newell
		normal[7] = v7;

		//Cara 8
		VerticeNormal** vn8 = new VerticeNormal*[7];
		vn8[0] = new VerticeNormal(33, 8);
		vn8[1] = new VerticeNormal(32, 8);
		vn8[2] = new VerticeNormal(38, 8);
		vn8[3] = new VerticeNormal(37, 8);
		vn8[4] = new VerticeNormal(36, 8);
		vn8[5] = new VerticeNormal(35, 8);
		vn8[6] = new VerticeNormal(34, 8);
		cara[8] = new Cara(7, vn8);
		PV3D* v8 = CalculoVectorNormalPorNewell(cara[8]); //Newell
		normal[8] = v8;

		//Cara 9
		VerticeNormal** vn9 = new VerticeNormal*[5];
		vn9[0] = new VerticeNormal(40, 9);
		vn9[1] = new VerticeNormal(41, 9);
		vn9[2] = new VerticeNormal(36, 9);
		vn9[3] = new VerticeNormal(37, 9);
		vn9[4] = new VerticeNormal(39, 9);
		cara[9] = new Cara(5, vn9);
		PV3D* v9 = CalculoVectorNormalPorNewell(cara[9]); //Newell
		normal[9] = v9;

		//Cara 10
		VerticeNormal** vn10 = new VerticeNormal*[8];
		vn10[0] = new VerticeNormal(4, 10);
		vn10[1] = new VerticeNormal(3, 10);
		vn10[2] = new VerticeNormal(6, 10);
		vn10[3] = new VerticeNormal(9, 10);
		vn10[4] = new VerticeNormal(30, 10);
		vn10[5] = new VerticeNormal(27, 10);
		vn10[6] = new VerticeNormal(23, 10);
		vn10[7] = new VerticeNormal(22, 10);
		cara[10] = new Cara(8, vn10);
		PV3D* v10 = CalculoVectorNormalPorNewell(cara[10]); //Newell
		normal[10] = v10;

		//Cara 11
		VerticeNormal** vn11 = new VerticeNormal*[4];
		vn11[0] = new VerticeNormal(9, 11);
		vn11[1] = new VerticeNormal(11, 11);
		vn11[2] = new VerticeNormal(31, 11);
		vn11[3] = new VerticeNormal(30, 11);
		cara[11] = new Cara(4, vn11);
		PV3D* v11 = CalculoVectorNormalPorNewell(cara[11]); //Newell
		normal[11] = v11;


		//Cara 12
		VerticeNormal** vn12 = new VerticeNormal*[4];
		vn12[0] = new VerticeNormal(11, 12);
		vn12[1] = new VerticeNormal(10, 12);
		vn12[2] = new VerticeNormal(32, 12);
		vn12[3] = new VerticeNormal(31, 12);
		cara[12] = new Cara(4, vn12);
		PV3D* v12 = CalculoVectorNormalPorNewell(cara[12]); //Newell
		normal[12] = v12;


		//Cara 13
		VerticeNormal** vn13 = new VerticeNormal*[4];
		vn13[0] = new VerticeNormal(10, 13);
		vn13[1] = new VerticeNormal(17, 13);
		vn13[2] = new VerticeNormal(38, 13);
		vn13[3] = new VerticeNormal(32, 13);
		cara[13] = new Cara(4, vn13);
		PV3D* v13 = CalculoVectorNormalPorNewell(cara[13]); //Newell
		normal[13] = v13;

		//Cara 14
		VerticeNormal** vn14 = new VerticeNormal*[4];
		vn14[0] = new VerticeNormal(17, 14);
		vn14[1] = new VerticeNormal(16, 14);
		vn14[2] = new VerticeNormal(37, 14);
		vn14[3] = new VerticeNormal(38, 14);
		cara[14] = new Cara(4, vn14);
		PV3D* v14 = CalculoVectorNormalPorNewell(cara[14]); //Newell
		normal[14] = v14;


		//Cara 15
		VerticeNormal** vn15 = new VerticeNormal*[4];
		vn15[0] = new VerticeNormal(16, 15);
		vn15[1] = new VerticeNormal(20, 15);
		vn15[2] = new VerticeNormal(39, 15);
		vn15[3] = new VerticeNormal(37, 15);
		cara[15] = new Cara(4, vn15);
		PV3D* v15 = CalculoVectorNormalPorNewell(cara[15]); //Newell
		normal[15] = v15;


		//Cara 16
		VerticeNormal** vn16 = new VerticeNormal*[4];
		vn16[0] = new VerticeNormal(0, 16);
		vn16[1] = new VerticeNormal(1, 16);
		vn16[2] = new VerticeNormal(25, 16);
		vn16[3] = new VerticeNormal(21, 16);
		cara[16] = new Cara(4, vn16);
		PV3D* v16 = CalculoVectorNormalPorNewell(cara[16]); //Newell
		normal[16] = v16;


		//Cara 17
		VerticeNormal** vn17 = new VerticeNormal*[4];
		vn17[0] = new VerticeNormal(1, 17);
		vn17[1] = new VerticeNormal(2, 17);
		vn17[2] = new VerticeNormal(24, 17);
		vn17[3] = new VerticeNormal(25, 17);
		cara[17] = new Cara(4, vn17);
		PV3D* v17 = CalculoVectorNormalPorNewell(cara[17]); //Newell
		normal[17] = v17;

		//Cara 18
		VerticeNormal** vn18 = new VerticeNormal*[4];
		vn18[0] = new VerticeNormal(2, 18);
		vn18[1] = new VerticeNormal(5, 18);
		vn18[2] = new VerticeNormal(26, 18);
		vn18[3] = new VerticeNormal(24, 18);
		cara[18] = new Cara(4, vn18);
		PV3D* v18 = CalculoVectorNormalPorNewell(cara[18]); //Newell
		normal[18] = v18;

		//Cara 19
		VerticeNormal** vn19 = new VerticeNormal*[4];
		vn19[0] = new VerticeNormal(5, 19);
		vn19[1] = new VerticeNormal(7, 19);
		vn19[2] = new VerticeNormal(28, 19);
		vn19[3] = new VerticeNormal(26, 19);
		cara[19] = new Cara(4, vn19);
		PV3D* v19 = CalculoVectorNormalPorNewell(cara[19]); //Newell
		normal[19] = v19;


		//Cara 20
		VerticeNormal** vn20 = new VerticeNormal*[8];
		vn20[0] = new VerticeNormal(7, 20);
		vn20[1] = new VerticeNormal(8, 20);
		vn20[2] = new VerticeNormal(12, 20);
		vn20[3] = new VerticeNormal(13, 20);
		vn20[4] = new VerticeNormal(34, 20);
		vn20[5] = new VerticeNormal(33, 20);
		vn20[6] = new VerticeNormal(29, 20);
		vn20[7] = new VerticeNormal(28, 20);
		cara[20] = new Cara(8, vn20);
		PV3D* v20 = CalculoVectorNormalPorNewell(cara[20]); //Newell
		normal[20] = v20;

		//Cara 21
		VerticeNormal** vn21 = new VerticeNormal*[4];
		vn21[0] = new VerticeNormal(13, 21);
		vn21[1] = new VerticeNormal(14, 21);
		vn21[2] = new VerticeNormal(35, 21);
		vn21[3] = new VerticeNormal(34, 21);
		cara[21] = new Cara(4, vn21);
		PV3D* v21 = CalculoVectorNormalPorNewell(cara[21]); //Newell
		normal[21] = v21;

		//Cara 22
		VerticeNormal** vn22 = new VerticeNormal*[4];
		vn22[0] = new VerticeNormal(14, 22);
		vn22[1] = new VerticeNormal(15, 22);
		vn22[2] = new VerticeNormal(36, 22);
		vn22[3] = new VerticeNormal(35, 22);
		cara[22] = new Cara(4, vn22);
		PV3D* v22 = CalculoVectorNormalPorNewell(cara[22]); //Newell
		normal[22] = v22;

		//Cara 23
		VerticeNormal** vn23 = new VerticeNormal*[4];
		vn23[0] = new VerticeNormal(15, 23);
		vn23[1] = new VerticeNormal(18, 23);
		vn23[2] = new VerticeNormal(41, 23);
		vn23[3] = new VerticeNormal(36, 23);
		cara[23] = new Cara(4, vn23);
		PV3D* v23 = CalculoVectorNormalPorNewell(cara[23]); //Newell
		normal[23] = v23;

		//Cara 24
		VerticeNormal** vn24 = new VerticeNormal*[4];
		vn24[0] = new VerticeNormal(18, 24);
		vn24[1] = new VerticeNormal(19, 24);
		vn24[2] = new VerticeNormal(40, 24);
		vn24[3] = new VerticeNormal(41, 24);
		cara[24] = new Cara(4, vn24);
		PV3D* v24 = CalculoVectorNormalPorNewell(cara[24]); //Newell
		normal[24] = v24;

		//Cara 25
		VerticeNormal** vn25 = new VerticeNormal*[4];
		vn25[0] = new VerticeNormal(0, 25);
		vn25[1] = new VerticeNormal(4, 25);
		vn25[2] = new VerticeNormal(22, 25);
		vn25[3] = new VerticeNormal(21, 25);
		cara[25] = new Cara(4, vn25);
		PV3D* v25 = CalculoVectorNormalPorNewell(cara[25]); //Newell
		normal[25] = v25;

		//Cara 26
		VerticeNormal** vn26 = new VerticeNormal*[4];
		vn26[0] = new VerticeNormal(40, 26);
		vn26[1] = new VerticeNormal(39, 26);
		vn26[2] = new VerticeNormal(20, 26);
		vn26[3] = new VerticeNormal(19, 26);
		cara[26] = new Cara(4, vn26);
		PV3D* v26 = CalculoVectorNormalPorNewell(cara[26]); //Newell
		normal[26] = v26;


}

Chasis::~Chasis() {
	// TODO Auto-generated destructor stub
}

