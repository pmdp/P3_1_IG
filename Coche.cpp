#include "Coche.h"


Coche::Coche() 
{
	//glEnable(GL_TEXTURE_2D);

	texture[0] = SOIL_load_OGL_texture
	("carbon.jpg",
	SOIL_LOAD_AUTO,
	SOIL_CREATE_NEW_ID,
	SOIL_FLAG_INVERT_Y
	);

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	//glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width,height, 0, GL_RGB, GL_UNSIGNED_BYTE, texture);	

	vDireccion = new PV3D(-1,0,0,0);
	// RUEDAS -------------------------------------------
	ruedas = new Ficha*[4];
	// Delantera izquierda
	ruedas[0] = new Ficha();
	addObjeto(ruedas[0]);
	ruedas[0]->mt->escala(new PV3D(1.5,1.5,1.5,1));
	ruedas[0]->mt->traslada(new PV3D(-2.6, 1, 1.4, 1));
	ruedas[0]->mt->rota(90, 1, 0, 0);

	// Trasera izquierda
	ruedas[1] = new Ficha();
	addObjeto(ruedas[1]);
	ruedas[1]->mt->escala(new PV3D(1.5,1.5,1.5,1));
	ruedas[1]->mt->traslada(new PV3D(2.6, 1, 1.4, 1));
	ruedas[1]->mt->rota(90, 1, 0, 0);



	// Delantera derecha
	ruedas[2] = new Ficha();
	addObjeto(ruedas[2]);
	ruedas[2]->mt->escala(new PV3D(1.5,1.5,1.5,1));
	ruedas[2]->mt->traslada(new PV3D(-2.6, 1, -1.4, 1));
	ruedas[2]->mt->rota(-90, 1, 0, 0);


	//Trasera derecha
	ruedas[3] = new Ficha();
	addObjeto(ruedas[3]);
	ruedas[3]->mt->escala(new PV3D(1.5,1.5,1.5,1));
	ruedas[3]->mt->traslada(new PV3D(2.6, 1, -1.4, 1));
	ruedas[3]->mt->rota(-90, 1, 0, 0);
	// ---------------------------------------------------

//	// CHASIS --------------------------------------------
//	addObjeto(new Cubo());
//	hijos[4]->mt->escala(new PV3D(4, 2, 2, 1));
//	hijos[4]->mt->traslada(new PV3D(0, 1, 0, 1));
//	hijos[4]->color->setColor(1, 0, 0);
//
//	addObjeto(new Cubo(1, texture, 1));
//	hijos[5]->mt->escala(new PV3D(2, 2, 2, 1));
//	hijos[5]->mt->traslada(new PV3D(0.5, 2, 0, 1));
//	hijos[5]->color->setColor(1, 0, 0);
//
//	// ---------------------------------------------------

	// FAROS ---------------------------------------------
	faro1 = new Cilindro(0.09,0.4,0.5,10,10);
	addObjeto(faro1);
	faro1->mt->traslada(new PV3D(-6.5,2.2,1.8,1));
	faro1->mt->rota(-90,0,1,0);
	faro1->color->setColor(0.5,0.5,0);
	faro2 = new Cilindro(0.09,0.4,0.5,10,10);
	addObjeto(faro2);
	faro2->mt->traslada(new PV3D(-6.5,2.2,-1.8,1));
	faro2->mt->rota(-90,0,1,0);
	faro2->color->setColor(0.5,0.5,0);
	// ---------------------------------------------------

	//CHASIS ---------------------------------------------
	chasis = new Chasis();
	addObjeto(chasis);
	chasis->mt->escala(new PV3D(0.6,0.6,0.6,1));
	chasis->color->setColor(1.0,0.0,0.0);
	chasis->mt->traslada(new PV3D(0,2.4,0,1));
	// ---------------------------------------------------

	// PUERTAS -------------------------------------------
	puertaIzq = new Puerta();
	puertaIzq->mt->escala(new PV3D(0.6,0.6,0.6,1));
	puertaIzq->mt->traslada(new PV3D(-3.0,2.2,4.0,1));
	puertaIzq->color->setColor(1.0,0.0,0.0);
	addObjeto(puertaIzq);
	puertaDrch = new Puerta();
	puertaDrch->mt->escala(new PV3D(0.6,0.6,0.6,1));
	puertaDrch->mt->traslada(new PV3D(-3.0,2.2,-4.0,1));
	puertaDrch->color->setColor(1.0,0.0,0.0);
	addObjeto(puertaDrch);
}

void Coche::openDoors(int angle){
	puertaIzq->mt->rota(-angle,0,1,0);
	puertaDrch->mt->rota(angle,0,1,0);
}

void Coche::closeDoors(int angle){
	puertaIzq->mt->rota(angle,0,1,0);
	puertaDrch->mt->rota(-angle,0,1,0);
}
void Coche::girar(float angle) 
{
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			ruedas[i]->mt->rota(angle, 0, 1, 0);
		else
			ruedas[i]->mt->rota(-angle, 0, 1, 0);
	}
}

