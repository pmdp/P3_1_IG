#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include "Camara.h"
#include "Escena.h"
#include <cmath>
#include <unistd.h>
#include <iostream>

using namespace std;


// Viewport size
int WIDTH= 800, HEIGHT= 600;

Camara* cam;
Escena* escena;

typedef enum CAR_DIR { LEFT, RIGHT, NONE } tCarDir;
tCarDir carDir;
float angleDoor;

// Viewing frustum parameters
	GLdouble xRight=10, xLeft=-xRight, yTop=10, yBot=-yTop, N=1, F=1000;
// Camera parameters
	GLdouble eyeX=100.0, eyeY=100.0, eyeZ=100.0;
	GLdouble lookX=0.0, lookY=0.0, lookZ=0.0;
	GLdouble upX=0, upY=1, upZ=0;

//Farola Position Light
GLfloat p1[4];
GLfloat dir[]={0.0, -1.0, 0.0};
bool light1On = true;

//Luces coche position
GLfloat p2[4];
GLfloat p3[4];
bool lightCoche = true;
GLfloat dir2[3];
//Opened cars door
bool openCarDoors = true;
bool closeCarDoor = false;


//Luz direccional remota 45
GLfloat p4[4];
bool lightRemota = true;

//Luz ambiente global
bool lightGlobal = true;
//Prototypes
void zoom (GLdouble f);


void buildSceneObjects()  {
	//Cámara
	PV3D* eye  = new PV3D(eyeX, eyeY, eyeZ, 1);
	PV3D* look = new PV3D(lookX, lookY, lookZ, 0);
	PV3D* up   = new PV3D(upX, upY, upZ, 0);
	cam = new Camara(eye, look, up, xRight, xLeft, yTop, yBot,N,F);

	escena = new Escena(200.0);

	carDir = NONE;
	angleDoor = 0;

	//Farola light position
	PV3D* pFarola = escena->farolas[escena->numFarolas/2]->mt->getPos();
	p1[0] = pFarola->getX(); p1[1] = pFarola->getY()+15; p1[2] = pFarola->getZ(); p1[3] = 1.0;

	//Car Lights Position
	PV3D* luz1 = escena->coche->faro1->mt->getPos();
	p2[0] = luz1->getX()-1;p2[1] = luz1->getY(); p2[2]= luz1->getZ(); p2[3]= 1.0;
	PV3D* luz2 = escena->coche->faro2->mt->getPos();
	p3[0] = luz2->getX()-1;p3[1] = luz2->getY(); p3[2]= luz2->getZ(); p3[3]= 1.0;
	dir2[0] = -1.0; dir2[1] =  0.0; dir2[2] =  0.0;

	cam->setLookAt(new PV3D(0,0,0,0), escena->coche->mt->getPos());
}

void initGL() {
	glClearColor(0.6f,0.7f,0.8f,1.0);
    glEnable(GL_LIGHTING);
   // glEnable(GL_TEXTURE_2D);


	glEnable(GL_COLOR_MATERIAL);
	glMaterialf(GL_FRONT, GL_SHININESS, 0.1f);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);


//	// Light0
//	glEnable(GL_LIGHT0);
//	GLfloat d[] = { 1.0, 1.0, 1.0, 1.0 };
//	glLightfv(GL_LIGHT0, GL_DIFFUSE, d);
//	GLfloat a[] = { 0.3f, 0.3f, 0.3f, 1.0 };
//	glLightfv(GL_LIGHT0, GL_AMBIENT, a);
//	GLfloat p[] = { 25.0, 25.0, 0.0, 1.0 };
//	glLightfv(GL_LIGHT0, GL_POSITION, p);

	//Light farola
	glEnable(GL_LIGHT1);
	GLfloat d[] = { 1.0, 0.0, 0, 1.0 };
	glLightfv(GL_LIGHT1, GL_DIFFUSE, d);
	GLfloat a[] = { 1.0, 0.0, 0.0, 1.0 };
	glLightfv(GL_LIGHT1, GL_AMBIENT, a);
	GLfloat esp0[] = {1.0,0.0,0.0,1.0};
	glLightfv(GL_LIGHT1, GL_SPECULAR, esp0);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 45.0);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 4.0);


	//Luces coche
	glEnable(GL_LIGHT2);
	GLfloat d2[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT2, GL_DIFFUSE, d2);
	GLfloat a2[] = { 0.3f, 0.3f, 0.3f, 1.0 };
	glLightfv(GL_LIGHT2, GL_AMBIENT, a2);

	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 45.0);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 4.0);


	glEnable(GL_LIGHT3);
	glLightfv(GL_LIGHT3, GL_DIFFUSE, d2);
	glLightfv(GL_LIGHT3, GL_AMBIENT, a2);
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 45.0);
	glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 4.0);


	//Luz remota direccional 45º
	glEnable(GL_LIGHT4);
	GLfloat d4[] = { 1.0, 1.0, 1.0, 1.0 };
	glLightfv(GL_LIGHT4, GL_DIFFUSE, d4);
	GLfloat a4[] = { 0.3f, 0.3f, 0.3f, 1.0 };
	glLightfv(GL_LIGHT4, GL_AMBIENT, a4);
	p4[0] = 30.0; p4[1] = 30.0; p4[2] = 30.0; p4[3] = 0.0;

//	glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, 1.5);
//	glLightf(GL_LIGHT1, GL_LINEAR_ATTENUATION, 0.5);
//	glLightf(GL_LIGHT1, GL_QUADRATIC_ATTENUATION, 0.2);

	buildSceneObjects();

}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//luz farola
	glLightfv(GL_LIGHT1, GL_POSITION, p1);

	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, dir);
	//Luces del coche, posición y dirección
	glLightfv(GL_LIGHT2, GL_POSITION, p2);//luz1 coche
	glLightfv(GL_LIGHT3, GL_POSITION, p3);//luz2 coche
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, dir2);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, dir2);
	//luz remota direccional 45
	glLightfv(GL_LIGHT4, GL_POSITION, p4);

	escena->dibuja();

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

void choqueCoche(){
	PV3D* pCoche = escena->coche->mt->getPos();
	for (int i = 0; i < escena->numFarolas; i++){
		Farola* f = escena->farolas[i];
		PV3D* pFarola = f->mt->getPos();
		if((abs(pCoche->getX()-pFarola->getX()) < 6) &&
				(abs(pCoche->getZ()-pFarola->getZ()) < 3) &&
					!f->caida){
			f->mt->rota(90,0,0,1);
			f->caida = true;
			if(i == escena->numFarolas/2)
				glDisable(GL_LIGHT1);
		}
	}
	for (int i = 0; i < escena->numTrees; i++){
			Tree* t = escena->trees[i];
			PV3D* pTree = t->mt->getPos();
			if((abs(pCoche->getX()-pTree->getX()) < 6)
				&& (abs(pCoche->getZ()-pTree->getZ()) < 3) &&
						!t->caido){
				t->mt->rota(90,0,0,1);
				t->caido = true;
			}
		}
//	if(abs(pCoche->getX()) > escena->escenaSize/2
//			|| (abs(pCoche->getZ()) > escena->escenaSize/2)){
//		escena->coche->mt->traslada(new PV3D(0,0,0,1));
//		cam->setLookAt(new PV3D(5,5,5,1), escena->coche->mt->getPos());
//		glutPostRedisplay();
//	}
}

void special_key(int key, int, int y)
{
	bool need_redisplay = true;
	switch (key) {
	case 101://up arrow
		escena->coche->mt->traslada(new PV3D(-1,0,0,1));
		escena->coche->girar(15);
		cam->setLookAt(new PV3D(-1,0,0,1), escena->coche->mt->getPos());
		p2[0]--; p3[0]--;
//		p2[0] = escena->coche->faro1->mt->getPos()->getX()-1;
//		p2[2] = escena->coche->faro1->mt->getPos()->getZ();
//		p3[0] = escena->coche->faro2->mt->getPos()->getX()-1;//Avanza luces coche
//		p3[2] = escena->coche->faro2->mt->getPos()->getZ();
		choqueCoche();
		if (carDir != NONE) {
			if (carDir == LEFT) {
				escena->coche->volante->mt->rota(-45, 0, 0, 1);
				escena->coche->ruedas[0]->mt->rota(45, 0, 0, 1);
				escena->coche->ruedas[2]->mt->rota(-45, 0, 0, 1);
			} else {
				escena->coche->volante->mt->rota(45, 0, 0, 1);
				escena->coche->ruedas[0]->mt->rota(-45, 0, 0, 1);
				escena->coche->ruedas[2]->mt->rota(45, 0, 0, 1);
			}
		}
		carDir = NONE;
		break;
	case 103://down arrow
		escena->coche->mt->traslada(new PV3D(1,0,0,1));
		escena->coche->girar(-15);
		cam->setLookAt(new PV3D(1,0,0,1), escena->coche->mt->getPos());
		p2[0]++;p3[0]++;//Mueve luces coche
		choqueCoche();
		if (carDir != NONE) {
			if (carDir == LEFT) {
				escena->coche->volante->mt->rota(-45, 0, 0, 1);
				escena->coche->ruedas[0]->mt->rota(45, 0, 0, 1);
				escena->coche->ruedas[2]->mt->rota(-45, 0, 0, 1);
			} else {
				escena->coche->volante->mt->rota(45, 0, 0, 1);
				escena->coche->ruedas[0]->mt->rota(-45, 0, 0, 1);
				escena->coche->ruedas[2]->mt->rota(45, 0, 0, 1);
			}
		}
		carDir = NONE;
		break;
	case 102://right arrow
		escena->coche->mt->rota(-10,0,1,0);
		if (carDir == NONE) {
			escena->coche->volante->mt->rota(-45, 0, 0, 1);
			escena->coche->ruedas[0]->mt->rota(45, 0, 0, 1);
			escena->coche->ruedas[2]->mt->rota(-45, 0, 0, 1);
		} else if (carDir == LEFT) {
			escena->coche->volante->mt->rota(90, 0, 0, 1);
			escena->coche->ruedas[0]->mt->rota(90, 0, 0, 1);
			escena->coche->ruedas[2]->mt->rota(-90, 0, 0, 1);
		}
		carDir = RIGHT;
		break;
	case 100://left arrow
		escena->coche->mt->rota(10,0,1,0);
		if (carDir == NONE) {
			escena->coche->volante->mt->rota(45, 0, 0, 1);
			escena->coche->ruedas[0]->mt->rota(-45, 0, 0, 1);
			escena->coche->ruedas[2]->mt->rota(45, 0, 0, 1);
		} else if (carDir == RIGHT) {
			escena->coche->volante->mt->rota(-90, 0, 0, 1);
			escena->coche->ruedas[0]->mt->rota(-90, 0, 0, 1);
			escena->coche->ruedas[2]->mt->rota(90, 0, 0, 1);
		}
		carDir = LEFT;
		break;
	default:
		need_redisplay = false;
		break;
	}
	if (need_redisplay)
		glutPostRedisplay();
}

static void timerOpenCarDoors(int time){
	if (angleDoor < 90) {
		angleDoor += 0.2f;
		escena->coche->openDoors(angleDoor);

		glutTimerFunc(250, timerOpenCarDoors, 1);
		glutPostRedisplay();
	} else 		
		closeCarDoor = true;
	
}

void timerCloseCarDoors(int time){
	if (angleDoor >= 0) {
		angleDoor -= 0.2f;
		escena->coche->openDoors(angleDoor);

		glutTimerFunc(25, timerCloseCarDoors, 1);
		glutPostRedisplay();
	} else {
		closeCarDoor = false;
		openCarDoors = true;
	}
	
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
			if(lightCoche){
				glDisable(GL_LIGHT2);
				glDisable(GL_LIGHT3);
				lightCoche = false;
			}
			else{
				glEnable(GL_LIGHT2);
				glEnable(GL_LIGHT3);
				lightCoche = true;
			}
			break;
		case 122://z
			if(lightRemota){
				glDisable(GL_LIGHT4);
				lightRemota = false;
				}
				else{
				glEnable(GL_LIGHT4);
				lightRemota = true;
				}
			break;
		case 115://s

			break;
		case 120://x
			if(lightGlobal){
				GLfloat amb[] = {0.0,0.0,0.0,1.0};
				glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);
				lightGlobal = false;
			}
			else{
				GLfloat amb[] = {0.2,0.2,0.2,1.0};
				glLightModelfv(GL_LIGHT_MODEL_AMBIENT, amb);
				lightGlobal = true;
			}
			break;
		case 100://d

			break;
		case 99://c
			if (openCarDoors) {
				openCarDoors = false;
				glutTimerFunc(250, timerOpenCarDoors, 1);
			} else if (closeCarDoor) {
				glutTimerFunc(250, timerCloseCarDoors, 1);
			}
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
			if(light1On){
				glDisable(GL_LIGHT1);
				light1On = false;
			}
			else{
				glEnable(GL_LIGHT1);
				light1On = true;
			}
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


