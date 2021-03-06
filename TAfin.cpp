#include "TAfin.h"

TAfin::TAfin()
{
	m[0]  = m[5]  = m[10] = m[15] = 1;
	m[1]  = m[2]  = m[3]  = m[4]  = m[6]  = 0;
	m[7]  = m[8]  = m[9]  = m[11] = m[12] = 0;
	m[13] = m[14] = 0;
}

void TAfin::traslada(PV3D* v)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		//glLoadMatrixf(m);  // Puede que haya que ponerlo
		glTranslatef(v->getX(), v->getY(), v->getZ());
		GLfloat m1[16];
		//Dejar la matriz actual de modelado-vista en m1
		glGetFloatv(GL_MODELVIEW_MATRIX, m1);
	glPopMatrix();

	postMultiplica(m1);
}
void TAfin::escala(PV3D* v)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		//glLoadMatrixf(m);
		glScalef(v->getX(), v->getY(), v->getZ());
		GLfloat m1[16];
        glGetFloatv(GL_MODELVIEW_MATRIX, m1);
	glPopMatrix();

	postMultiplica(m1);
}

void TAfin::rota(float angle, float x, float y, float z)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
    	glLoadIdentity();
        //glLoadMatrixf(m);
        glRotatef(angle, x, y, z);
        GLfloat m1[16];
        glGetFloatv(GL_MODELVIEW_MATRIX, m1);
	glPopMatrix();

	postMultiplica(m1);
}

void TAfin::postMultiplica(GLfloat* m1)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadMatrixf(m); //Cargar m como matriz actual de modelado-vista
		glMultMatrixf(m1); //Post-multiplicar por m1
		glGetFloatv(GL_MODELVIEW_MATRIX, m); //Dejar el resultado en m
	glPopMatrix();
}

PV3D* TAfin::getPos(){
	return new PV3D(m[12],m[13],m[14],m[15]);
}
