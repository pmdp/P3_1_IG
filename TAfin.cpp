#include "TAfin.h"

TAfin::TAfin()
{
	_m[0]  = _m[5]  = _m[10] = _m[15] = 1;
	_m[1]  = _m[2]  = _m[3]  = _m[4]  = _m[6]  = 0;
	_m[7]  = _m[8]  = _m[9]  = _m[11] = _m[12] = 0;
	_m[13] = _m[14] = 0;
}

void TAfin::translada(PV3D* v)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
	   	//glLoadMatrixd(_m);  // Puede que haya que ponerlo
		glTranslatef(v->getX(), v->getY(), v->getZ());
		GLfloat m1[16];

		m1[0] = _m[0]; m1[4] = _m[4]; m1[8]  = _m[8];  m1[12] = _m[12];
		m1[1] = _m[1]; m1[5] = _m[5]; m1[9]  = _m[9];  m1[13] = _m[13];
		m1[2] = _m[2]; m1[6] = _m[6]; m1[10] = _m[10]; m1[14] = _m[14];
		m1[3] = _m[3]; m1[7] = _m[7]; m1[11] = _m[11]; m1[15] = _m[15];

		glGetFloatv(GL_MODELVIEW_MATRIX, m1);
	glPopMatrix();

	postMultiplica(m1);
}

void TAfin::rota(float angle, float x, float y, float z)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
    	glLoadIdentity();
        glLoadMatrixf(_m);
        glRotated(angle, x, y, z);
        glGetFloatv(GL_MODELVIEW_MATRIX, _m);
	glPopMatrix();
}

void TAfin::postMultiplica(GLfloat* m1)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadMatrixf(_m); //Cargar m como matriz actual de modelado-vista
		glMultMatrixf(m1); //Post-multiplicar por m1
		glGetFloatv(GL_MODELVIEW_MATRIX, _m); //Dejar el resultado en m
	glPopMatrix();
}
