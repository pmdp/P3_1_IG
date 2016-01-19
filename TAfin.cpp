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
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		//glLoadMatrixd(m);  // Puede que haya que ponerlo
		glTranslatef(v->getX(), v->getY(), v->getZ());
		GLfloat m1[16];

		m1[0] = m[0]; m1[4] = m[4]; m1[8]  = m[8];  m1[12] = m[12];
		m1[1] = m[1]; m1[5] = m[5]; m1[9]  = m[9];  m1[13] = m[13];
		m1[2] = m[2]; m1[6] = m[6]; m1[10] = m[10]; m1[14] = m[14];
		m1[3] = m[3]; m1[7] = m[7]; m1[11] = m[11]; m1[15] = m[15];

		glGetFloatv(GL_MODELVIEW_MATRIX, m1);
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
