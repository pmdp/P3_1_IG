#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "Cubo.h"
#include "Camara.h"
#include <iostream>
#include "SOIL.h"
using namespace std;


// Viewport size
int WIDTH= 800, HEIGHT= 600;

GLdouble xRight=10, xLeft=-xRight, yTop=10, yBot=-yTop, N=1, F=1000;
GLdouble eyeX=100.0, eyeY=100.0, eyeZ=100.0;
GLdouble lookX=0.0, lookY=0.0, lookZ=0.0;
GLdouble upX=0, upY=1, upZ=0;

Cubo* cubo;
Camara* cam;
GLuint	texture[1];

void zoom (GLdouble f);

void applyTexture() {
	GLuint texturas[2];
    glGenTextures(2,texturas);
 
    glEnable(GL_TEXTURE_2D);
 
    //Leer archivo
    int width = 1024;
    int height = 768;
    unsigned char* image = SOIL_load_image("carbon.jpg", &width, &height, 0, SOIL_LOAD_RGB);
 
    glBindTexture(GL_TEXTURE_2D, texturas[0]);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glTexImage2D(GL_TEXTURE_2D, 2, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);


	glEnable(GL_TEXTURE_2D);
	cubo = new Cubo(2, texturas, 4);
	cubo->color->setColor(1, 0, 0);
}

int LoadGLTextures()
{
	texture[0] = SOIL_load_OGL_texture
	("carbon.jpg",
	SOIL_LOAD_AUTO,
	SOIL_CREATE_NEW_ID,
	SOIL_FLAG_INVERT_Y
	);

	if(texture[0] == 0)
		return false;

	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);

	return true;										
}

void drawExample() {
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glBegin(GL_QUADS);

		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);

		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);

		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);

		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);

		glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
		glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);

		glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);
		glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);
		glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);
		glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);

	glEnd();
}

void buildSceneObjects() {
	//applyTexture();

	//Cámara
	PV3D* eye  = new PV3D(eyeX, eyeY, eyeZ, 1);
	PV3D* look = new PV3D(lookX, lookY, lookZ, 0);
	PV3D* up   = new PV3D(upX, upY, upZ, 0);
	cam = new Camara(eye, look, up, xRight, xLeft, yTop, yBot,N,F);

	//applyTexture();
}

void initGL() {
	LoadGLTextures();	

	glClearColor(0.6f,0.7f,0.8f,1.0);
    glEnable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);

	glEnable(GL_COLOR_MATERIAL);
	glMaterialf(GL_FRONT, GL_SHININESS, 0.1f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);


	// Light0
	glEnable(GL_LIGHT0);
	GLfloat d[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
	GLfloat a[] = { 0.3f, 0.3f, 0.3f, 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, a);
	GLfloat p[] = { 25.0, 25.0, 0.0, 1.0 };
	glLightfv(GL_LIGHT0, GL_POSITION, p);

	buildSceneObjects();
}


void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//cubo->dibuja();
	drawExample();

	glFlush();
	glutSwapBuffers();
}

void resize(int newWidth, int newHeight) {
	WIDTH= newWidth;
	HEIGHT= newHeight;
	GLdouble RatioViewPort= (float)WIDTH/(float)HEIGHT;
	glViewport (0, 0, WIDTH, HEIGHT) ;

	GLdouble SVAWidth= xRight-xLeft;
	GLdouble SVAHeight= yTop-yBot;
	GLdouble SVARatio= SVAWidth/SVAHeight;
	if (SVARatio >= RatioViewPort) {
		GLdouble newHeight= SVAWidth/RatioViewPort;
		GLdouble yMiddle= ( yBot+yTop )/2.0;
		yTop= yMiddle + newHeight/2.0;
		yBot= yMiddle - newHeight/2.0;
    }
	else {
		GLdouble newWidth= SVAHeight*RatioViewPort;
		GLdouble xMiddle= ( xLeft+xRight )/2.0;
		xRight= xMiddle + newWidth/2.0;
		xLeft=  xMiddle - newWidth/2.0;
	}

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(xLeft, xRight, yBot, yTop, N, F);
}

void special_key(int key, int, int y)
{
	bool need_redisplay = true;
	switch (key) {
	case 101://up arrow
		break;
	case 103://down arrow
		break;
	case 102://right arrow
		break;
	case 100://left arrow
		break;
	default:
		need_redisplay = false;
		break;
	}
	if (need_redisplay)
		glutPostRedisplay();
}


void key(unsigned char key, int x, int y){
	bool need_redisplay = true;
	switch (key) {
		case 27:
			glutLeaveMainLoop ();
			break;
		case 116://t
			zoom(1.25);
			break;
		case 121://y
			zoom(0.75);
			break;
		case 97://a
			break;
		case 122://z
			break;
		case 115://s

			break;
		case 120://x
			break;
		case 100://d

			break;
		case 99://c

			break;
		case 101://e
			cam->recorridoEje(-7, 0, 0);
			break;
		case 114://r
			cam->recorridoEje(7, 0, 0);
			break;
		case 102://f
			cam->recorridoEje(0, -7, 0);
			break;
		case 103://g
			cam->recorridoEje(0, 7, 0);
			break;
		case 118://v
			cam->recorridoEje(0, 0, -7);
			break;
		case 98://b
			cam->recorridoEje(0, 0, 7);
			break;
		case 49://1
			cam->giraX();
			break;
		case 50://2
			cam->giraY();
			break;
		case 51://3
			cam->giraZ();
			break;
		case 52://4
			cam->lateral();
			break;
		case 53://5
			cam->frontal();
			break;
		case 54://6
			cam->cenital();
			break;
		case 55://7
			cam->esquina();
			break;
		case 56://8
			cam->perspectiva();
			break;
		case 57://9
			cam->ortogonal();
			break;
		case 117://u
			cam->roll(2.0);
			break;
		case 105://i
			cam->roll(-2.0);
			break;
		case 106://j
			cam->yaw(2.0);
			break;
		case 107://k
			cam->yaw(-2.0);
			break;
		case 109://m
			cam->pitch(-2.0);
			break;
		case 110://n
			cam->pitch(2.0);
			break;
		case 32://espacio
			glutFullScreenToggle();
			break;
		case 108://l
			break;
		default:
			need_redisplay = false;
			break;
	}

	if (need_redisplay)
		glutPostRedisplay();
}

void zoom (GLdouble f) {
	GLdouble anchoNew = (xRight - xLeft) / f;
	GLdouble altoNew = (yTop - yBot) / f;
	GLdouble centroX = (xLeft + xRight) / 2.0;
	GLdouble centroY = (yTop + yBot) / 2.0;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(centroX-anchoNew/2.0, centroX+anchoNew/2.0, centroY-altoNew/2.0, centroY+altoNew/2.0, N, F);
	display();

	xLeft = centroX - anchoNew / 2.0;
	xRight = centroX + anchoNew / 2.0;
	yBot = centroY - altoNew / 2.0;
	yTop = centroY + altoNew / 2.0;
}

int main(int argc, char *argv[]){
	cout<< "Starting console..." << endl;

	// Initialization
	glutInitWindowSize(WIDTH, HEIGHT);
	glutInitWindowPosition (140, 140);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);

	// Window construction
	glutCreateWindow("Practica 3");

	// Callback registration
	glutReshapeFunc(resize);
	glutKeyboardFunc(key);
	glutSpecialFunc(special_key);
	glutDisplayFunc(display);
	// OpenGL basic setting
	initGL();

	// Freeglut's main loop can be stopped executing (**)
	// while (continue_in_main_loop) glutMainLoopEvent();

	// Classic glut's main loop can be stopped after X-closing the window,
	// using the following freeglut's setting (*)
	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

	// Classic glut's main loop can be stopped in freeglut using (*)
	glutMainLoop();

	// We would never reach this point using classic glut
	//system("PAUSE");


	return 0;
}


