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
		glTranslatef(v->getX(), v->getY(), v->getZ());
		GLfloat m1[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, m1);
	glPopMatrix();

	postMultiplica(m1);
}
void TAfin::escala(PV3D* v)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadIdentity();
		glScaled(v->getX(), v->getY(), v->getZ());
		glGetFloatv(GL_MODELVIEW_MATRIX, m);
	glPopMatrix();
}

void TAfin::rota(float angle, float x, float y, float z)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
    	glLoadIdentity();
        glRotated(angle, x, y, z);
		glGetFloatv(GL_MODELVIEW_MATRIX, m);
	glPopMatrix();
}

void TAfin::postMultiplica(GLfloat* m1)
{
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
		glLoadMatrixf(m); 
		glMultMatrixf(m1);
		glGetFloatv(GL_MODELVIEW_MATRIX, m); 
	glPopMatrix();
}
