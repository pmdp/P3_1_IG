#include "TAfin.h"

TAfin::TAfin()
{
	m[0]  = m[5]  = m[10] = m[15] = 1;
	m[1]  = m[2]  = m[3]  = m[4]  = m[6]  = 0;
	m[7]  = m[8]  = m[9]  = m[11] = m[12] = 0;
	m[13] = m[14] = 0;
}

void TAfin::translada(PV3D* v)
{
	GLfloat m1[16];
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		glLoadMatrixf(m); 
		glTranslatef(v->getX(), v->getY(), v->getZ());
		glGetFloatv(GL_MODELVIEW_MATRIX, m);
	glPopMatrix();
	postMultiplica(m1);
}
void TAfin::escala(PV3D* v)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		glLoadMatrixf(m);
		glScaled(v->getX(), v->getY(), v->getZ());
        glGetFloatv(GL_MODELVIEW_MATRIX, m);
	glPopMatrix();
}

void TAfin::rota(float angle, float x, float y, float z)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
    	glLoadIdentity();
        glLoadMatrixf(m);
        glRotated(angle, x, y, z);
        glGetFloatv(GL_MODELVIEW_MATRIX, m);
	glPopMatrix();
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
