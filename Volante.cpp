#include "Volante.h"

Volante::Volante() {
	numVertices = 34;
	numCaras = 32;
	numNormales = numCaras;

	vertice = new PV3D*[numVertices];
	normal = new PV3D*[numNormales];
	cara = new Cara*[numCaras];

	//Vertices
	vertice[0] = new PV3D(-3.5, 0.0, 1.0, 1);
	vertice[1] = new PV3D(-2.5, 0.0, 1.0, 1);
	vertice[2] = new PV3D(-3.0, 1.0, 1.0, 1);
	vertice[3] = new PV3D(-4.5, 3.0, 1.0, 1);
	vertice[4] = new PV3D(-5.5, 3.0, 1.0, 1);
	vertice[5] = new PV3D(-1.5, 0.0, 1.0, 1);
	vertice[6] = new PV3D(-1.5, 1.0, 1.0, 1);
	vertice[7] = new PV3D(-0.5, 1.0, 1.0, 1);
	vertice[8] = new PV3D(-0.5, 2.0, 1.0, 1);
	vertice[9] = new PV3D(0.5, 1.0, 1.0, 1);
	vertice[10] = new PV3D(0.5, 2.0, 1.0, 1);
	vertice[11] = new PV3D(1.5, 0.0, 1.0, 1);
	vertice[12] = new PV3D(1.5, 1.0, 1.0, 1);
	vertice[13] = new PV3D(2.5, 0.0, 1.0, 1);
	vertice[14] = new PV3D(3.0, 1.0, 1.0, 1);
	vertice[15] = new PV3D(3.5, 0.0, 1.0, 1);
	vertice[16] = new PV3D(5.5, 3.0, 1.0, 1);
	vertice[17] = new PV3D(4.5, 3.0, 1.0, 1);

	//Vertices Cara trasera
	vertice[18] = new PV3D(-3.5, 0.0, 0.0, 1);
	vertice[19] = new PV3D(-2.5, 0.0, 0.0, 1);
	vertice[20] = new PV3D(-3.0, 1.0, 0.0, 1);
	vertice[21] = new PV3D(-4.5, 3.0, 0.0, 1);
	vertice[22] = new PV3D(-5.5, 3.0, 0.0, 1);
	vertice[23] = new PV3D(-1.5, 0.0, 0.0, 1);
	vertice[24] = new PV3D(-1.5, 1.0, 0.0, 1);
	vertice[25] = new PV3D(-0.5, 1.0, 0.0, 1);
	vertice[26] = new PV3D(-0.5, 2.0, 0.0, 1);
	vertice[27] = new PV3D(0.5, 1.0, 0.0, 1);
	vertice[28] = new PV3D(0.5, 2.0, 0.0, 1);
	vertice[29] = new PV3D(1.5, 0.0, 0.0, 1);
	vertice[30] = new PV3D(1.5, 1.0, 0.0, 1);
	vertice[31] = new PV3D(2.5, 0.0, 0.0, 1);
	vertice[32] = new PV3D(3.0, 1.0, 0.0, 1);
	vertice[33] = new PV3D(3.5, 0.0, 0.0, 1);
	vertice[34] = new PV3D(5.5, 3.0, 0.0, 1);
	vertice[35] = new PV3D(4.5, 3.0, 0.0, 1);


// DELANTERA -------------------------------------------------
	//Cara 1
	VerticeNormal** vn0 = new VerticeNormal*[5];
	vn0[0] = new VerticeNormal(0, 0);
	vn0[1] = new VerticeNormal(1, 0);
	vn0[2] = new VerticeNormal(2, 0);
	vn0[3] = new VerticeNormal(3, 0);
	vn0[4] = new VerticeNormal(4, 0);
	cara[0] = new Cara(5, vn0);
	PV3D* v0 = CalculoVectorNormalPorNewell(cara[0]); //Newell
	normal[0] = v0;

	//Cara 2
	VerticeNormal** vn1 = new VerticeNormal*[4];
	vn1[0] = new VerticeNormal(1, 1);
	vn1[1] = new VerticeNormal(5, 1);
	vn1[2] = new VerticeNormal(6, 1);
	vn1[3] = new VerticeNormal(2, 1);
	cara[1] = new Cara(4, vn1);
	PV3D* v1 = CalculoVectorNormalPorNewell(cara[1]); //Newell
	normal[1] = v1;

	//Cara 3 
	VerticeNormal** vn2 = new VerticeNormal*[4];
	vn2[0] = new VerticeNormal(5, 2);
	vn2[1] = new VerticeNormal(7, 2);
	vn2[2] = new VerticeNormal(8, 2);
	vn2[3] = new VerticeNormal(6, 2);
	cara[2] = new Cara(4, vn2);
	PV3D* v2 = CalculoVectorNormalPorNewell(cara[2]); //Newell
	normal[2] = v2;

	//Cara 4
	VerticeNormal** vn3 = new VerticeNormal*[4];
	vn3[0] = new VerticeNormal(7, 3);
	vn3[1] = new VerticeNormal(9, 3);
	vn3[2] = new VerticeNormal(10,3);
	vn3[3] = new VerticeNormal(8, 3);
	cara[3] = new Cara(4, vn3);
	PV3D* v3 = CalculoVectorNormalPorNewell(cara[3]); //Newell
	normal[3] = v3;

	//Cara 5
	VerticeNormal** vn4 = new VerticeNormal*[4];
	vn4[0] = new VerticeNormal(9,  4);
	vn4[1] = new VerticeNormal(11, 4);
	vn4[2] = new VerticeNormal(12, 4);
	vn4[3] = new VerticeNormal(10, 4);
	cara[4] = new Cara(4, vn4);
	PV3D* v4 = CalculoVectorNormalPorNewell(cara[4]); //Newell
	normal[4] = v4;

	//Cara 6
	VerticeNormal** vn5 = new VerticeNormal*[4];
	vn5[0] = new VerticeNormal(11, 5);
	vn5[1] = new VerticeNormal(13, 5);
	vn5[2] = new VerticeNormal(14, 5);
	vn5[3] = new VerticeNormal(12, 5);
	cara[5] = new Cara(4, vn5);
	PV3D* v5 = CalculoVectorNormalPorNewell(cara[5]); //Newell
	normal[5] = v5;

	//Cara 7
	VerticeNormal** vn6 = new VerticeNormal*[5];
	vn6[0] = new VerticeNormal(13, 6);
	vn6[1] = new VerticeNormal(15, 6);
	vn6[2] = new VerticeNormal(16, 6);
	vn6[3] = new VerticeNormal(17, 6);
	vn6[4] = new VerticeNormal(14, 6);
	cara[6] = new Cara(5, vn6);
	PV3D* v6 = CalculoVectorNormalPorNewell(cara[6]); //Newell
	normal[6] = v6;

// TRASERA-----------------------------------------------------
	//Cara 8
	VerticeNormal** vn7 = new VerticeNormal*[5];
	vn7[0] = new VerticeNormal(18, 7);
	vn7[1] = new VerticeNormal(19, 7);
	vn7[2] = new VerticeNormal(20, 7);
	vn7[3] = new VerticeNormal(21, 7);
	vn7[4] = new VerticeNormal(22, 7);
	cara[7] = new Cara(5, vn7);
	PV3D* v7 = CalculoVectorNormalPorNewell(cara[7]); //Newell
	normal[7] = v7;

	//Cara 9
	VerticeNormal** vn8 = new VerticeNormal*[4];
	vn8[0] = new VerticeNormal(19, 8);
	vn8[1] = new VerticeNormal(23, 8);
	vn8[2] = new VerticeNormal(24, 8);
	vn8[3] = new VerticeNormal(20, 8);
	cara[8] = new Cara(4, vn8);
	PV3D* v8 = CalculoVectorNormalPorNewell(cara[8]); //Newell
	normal[8] = v8;

	//Cara 10 
	VerticeNormal** vn9 = new VerticeNormal*[4];
	vn9[0] = new VerticeNormal(23, 9);
	vn9[1] = new VerticeNormal(25, 9);
	vn9[2] = new VerticeNormal(26, 9);
	vn9[3] = new VerticeNormal(24, 9);
	cara[9] = new Cara(4, vn9);
	PV3D* v9 = CalculoVectorNormalPorNewell(cara[9]); //Newell
	normal[9] = v9;

	//Cara 11
	VerticeNormal** vn10 = new VerticeNormal*[4];
	vn10[0] = new VerticeNormal(25, 10);
	vn10[1] = new VerticeNormal(27, 10);
	vn10[2] = new VerticeNormal(28, 10);
	vn10[3] = new VerticeNormal(26, 10);
	cara[10] = new Cara(4, vn10);
	PV3D* v10 = CalculoVectorNormalPorNewell(cara[10]); //Newell
	normal[10] = v10;

	//Cara 12
	VerticeNormal** vn11 = new VerticeNormal*[4];
	vn11[0] = new VerticeNormal(27, 11);
	vn11[1] = new VerticeNormal(29, 11);
	vn11[2] = new VerticeNormal(30, 11);
	vn11[3] = new VerticeNormal(28, 11);
	cara[11] = new Cara(4, vn11);
	PV3D* v11 = CalculoVectorNormalPorNewell(cara[11]); //Newell
	normal[11] = v11;

	//Cara 13
	VerticeNormal** vn12 = new VerticeNormal*[4];
	vn12[0] = new VerticeNormal(29, 12);
	vn12[1] = new VerticeNormal(31, 12);
	vn12[2] = new VerticeNormal(32, 12);
	vn12[3] = new VerticeNormal(30, 12);
	cara[12] = new Cara(4, vn12);
	PV3D* v12 = CalculoVectorNormalPorNewell(cara[12]); //Newell
	normal[12] = v12;

	//Cara 14
	VerticeNormal** vn13 = new VerticeNormal*[5];
	vn13[0] = new VerticeNormal(31, 13);
	vn13[1] = new VerticeNormal(33, 13);
	vn13[2] = new VerticeNormal(34, 13);
	vn13[3] = new VerticeNormal(35, 13);
	vn13[4] = new VerticeNormal(32, 13);
	cara[13] = new Cara(5, vn13);
	PV3D* v13 = CalculoVectorNormalPorNewell(cara[13]); //Newell
	normal[13] = v13;

// UNION DE LAS CARAS -------------------------------------------
	//Cara 15
	VerticeNormal** vn14 = new VerticeNormal*[4];
	vn14[0] = new VerticeNormal(18, 14);
	vn14[1] = new VerticeNormal(0, 14);
	vn14[2] = new VerticeNormal(4, 14);
	vn14[3] = new VerticeNormal(22, 14);
	cara[14] = new Cara(4, vn14);
	PV3D* v14 = CalculoVectorNormalPorNewell(cara[14]); //Newell
	normal[14] = v14;

	//Cara 16
	VerticeNormal** vn15 = new VerticeNormal*[4];
	vn15[0] = new VerticeNormal(18, 15);
	vn15[1] = new VerticeNormal(20, 15);
	vn15[2] = new VerticeNormal(21, 15);
	vn15[3] = new VerticeNormal(3, 15);
	cara[15] = new Cara(4, vn15);
	PV3D* v15 = CalculoVectorNormalPorNewell(cara[15]); //Newell
	normal[15] = v15;

	//Cara 17 
	VerticeNormal** vn16 = new VerticeNormal*[4];
	vn16[0] = new VerticeNormal(4, 16);
	vn16[1] = new VerticeNormal(3, 16);
	vn16[2] = new VerticeNormal(21, 16);
	vn16[3] = new VerticeNormal(22, 16);
	cara[16] = new Cara(4, vn16);
	PV3D* v16 = CalculoVectorNormalPorNewell(cara[16]); //Newell
	normal[16] = v16;

	//Cara 18
	VerticeNormal** vn17 = new VerticeNormal*[4];
	vn17[0] = new VerticeNormal(0, 17);
	vn17[1] = new VerticeNormal(1, 17);
	vn17[2] = new VerticeNormal(19, 17);
	vn17[3] = new VerticeNormal(18, 17);
	cara[17] = new Cara(4, vn17);
	PV3D* v17 = CalculoVectorNormalPorNewell(cara[17]); //Newell
	normal[17] = v17;

	//Cara 19
	VerticeNormal** vn18 = new VerticeNormal*[4];
	vn18[0] = new VerticeNormal(2, 18);
	vn18[1] = new VerticeNormal(6, 18);
	vn18[2] = new VerticeNormal(24, 18);
	vn18[3] = new VerticeNormal(20, 18);
	cara[18] = new Cara(4, vn18);
	PV3D* v18 = CalculoVectorNormalPorNewell(cara[18]); //Newell
	normal[18] = v18;

	//Cara 20
	VerticeNormal** vn19 = new VerticeNormal*[4];
	vn19[0] = new VerticeNormal(1, 19);
	vn19[1] = new VerticeNormal(5, 19);
	vn19[2] = new VerticeNormal(23, 19);
	vn19[3] = new VerticeNormal(19, 19);
	cara[19] = new Cara(4, vn19);
	PV3D* v19 = CalculoVectorNormalPorNewell(cara[19]); //Newell
	normal[19] = v19;

	//Cara 21 
	VerticeNormal** vn20 = new VerticeNormal*[4];
	vn20[0] = new VerticeNormal(6, 20);
	vn20[1] = new VerticeNormal(8, 20);
	vn20[2] = new VerticeNormal(26, 20);
	vn20[3] = new VerticeNormal(24, 20);
	cara[20] = new Cara(4, vn20);
	PV3D* v20 = CalculoVectorNormalPorNewell(cara[20]); //Newell
	normal[20] = v20;

	//Cara 22
	VerticeNormal** vn21 = new VerticeNormal*[4];
	vn21[0] = new VerticeNormal(5, 21);
	vn21[1] = new VerticeNormal(7, 21);
	vn21[2] = new VerticeNormal(25, 21);
	vn21[3] = new VerticeNormal(23, 21);
	cara[21] = new Cara(4, vn21);
	PV3D* v21 = CalculoVectorNormalPorNewell(cara[21]); //Newell
	normal[21] = v21;

	//Cara 23
	VerticeNormal** vn22 = new VerticeNormal*[4];
	vn22[0] = new VerticeNormal(8, 22);
	vn22[1] = new VerticeNormal(10, 22);
	vn22[2] = new VerticeNormal(28, 22);
	vn22[3] = new VerticeNormal(26, 22);
	cara[22] = new Cara(4, vn22);
	PV3D* v22 = CalculoVectorNormalPorNewell(cara[22]); //Newell
	normal[22] = v22;

	//Cara 24
	VerticeNormal** vn23 = new VerticeNormal*[4];
	vn23[0] = new VerticeNormal(7, 23);
	vn23[1] = new VerticeNormal(9, 23);
	vn23[2] = new VerticeNormal(27, 23);
	vn23[3] = new VerticeNormal(25, 23);
	cara[23] = new Cara(4, vn23);
	PV3D* v23 = CalculoVectorNormalPorNewell(cara[23]); //Newell
	normal[23] = v23;

	//Cara 25 
	VerticeNormal** vn24 = new VerticeNormal*[4];
	vn24[0] = new VerticeNormal(10, 24);
	vn24[1] = new VerticeNormal(12, 24);
	vn24[2] = new VerticeNormal(30, 24);
	vn24[3] = new VerticeNormal(28, 24);
	cara[24] = new Cara(4, vn24);
	PV3D* v24 = CalculoVectorNormalPorNewell(cara[24]); //Newell
	normal[24] = v24;

	//Cara 26
	VerticeNormal** vn25 = new VerticeNormal*[4];
	vn25[0] = new VerticeNormal(9, 25);
	vn25[1] = new VerticeNormal(11, 25);
	vn25[2] = new VerticeNormal(29, 25);
	vn25[3] = new VerticeNormal(27, 25);
	cara[25] = new Cara(4, vn25);
	PV3D* v25 = CalculoVectorNormalPorNewell(cara[25]); //Newell
	normal[25] = v25;

	//Cara 27
	VerticeNormal** vn26 = new VerticeNormal*[4];
	vn26[0] = new VerticeNormal(12, 26);
	vn26[1] = new VerticeNormal(14, 26);
	vn26[2] = new VerticeNormal(32, 26);
	vn26[3] = new VerticeNormal(30, 26);
	cara[26] = new Cara(4, vn26);
	PV3D* v26 = CalculoVectorNormalPorNewell(cara[26]); //Newell
	normal[26] = v26;

	//Cara 28
	VerticeNormal** vn27 = new VerticeNormal*[4];
	vn27[0] = new VerticeNormal(11, 27);
	vn27[1] = new VerticeNormal(13, 27);
	vn27[2] = new VerticeNormal(31, 27);
	vn27[3] = new VerticeNormal(29, 27);
	cara[27] = new Cara(4, vn27);
	PV3D* v27 = CalculoVectorNormalPorNewell(cara[27]); //Newell
	normal[27] = v27;

	//Cara 29 
	VerticeNormal** vn28 = new VerticeNormal*[4];
	vn28[0] = new VerticeNormal(32, 28);
	vn28[1] = new VerticeNormal(14, 28);
	vn28[2] = new VerticeNormal(17, 28);
	vn28[3] = new VerticeNormal(35, 28);
	cara[28] = new Cara(4, vn28);
	PV3D* v28 = CalculoVectorNormalPorNewell(cara[28]); //Newell
	normal[28] = v28;

	//Cara 30
	VerticeNormal** vn29 = new VerticeNormal*[4];
	vn29[0] = new VerticeNormal(17, 29);
	vn29[1] = new VerticeNormal(16, 29);
	vn29[2] = new VerticeNormal(34, 29);
	vn29[3] = new VerticeNormal(35, 29);
	cara[29] = new Cara(4, vn29);
	PV3D* v29 = CalculoVectorNormalPorNewell(cara[29]); //Newell
	normal[29] = v29;

	//Cara 31
	VerticeNormal** vn30 = new VerticeNormal*[4];
	vn30[0] = new VerticeNormal(15, 30);
	vn30[1] = new VerticeNormal(33, 30);
	vn30[2] = new VerticeNormal(34, 30);
	vn30[3] = new VerticeNormal(16, 30);
	cara[30] = new Cara(4, vn30);
	PV3D* v30 = CalculoVectorNormalPorNewell(cara[30]); //Newell
	normal[30] = v30;

	//Cara 32
	VerticeNormal** vn31 = new VerticeNormal*[4];
	vn31[0] = new VerticeNormal(13, 31);
	vn31[1] = new VerticeNormal(15, 31);
	vn31[2] = new VerticeNormal(33, 31);
	vn31[3] = new VerticeNormal(31, 31);
	cara[31] = new Cara(4, vn31);
	PV3D* v31 = CalculoVectorNormalPorNewell(cara[31]); //Newell
	normal[31] = v31;

}


