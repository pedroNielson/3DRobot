#include <GL/glut.h>
#include <GL/GLU.h>
#include <math.h>
#include <Windows.h>
#include <iostream>
#include "tgaload.h"

#define MAX_NO_TEXTURES 4

#define BRICK_TEXTURE 0
#define CUBE_TEXTURE 1



using namespace std;

GLuint texture_id[MAX_NO_TEXTURES];
float angle = 0.0f;

void callKeyboard(unsigned char KEY, int x, int y)
{
	if (KEY == 27)
		exit(0);
	if (KEY == 'a')
	{
		angle -= 20.0;
		cout << angle << endl;

	}

	else
		if (KEY == 'd')
		{
			angle += 20.0;
			cout << angle << endl;
		}

	if (KEY == 'r')
	{
		angle = 0;
		cout << angle << endl;
	}
	glutPostRedisplay();
}


void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);

	float aspect = (float)w / (float)h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, aspect, 0.1, 500.0);

	glMatrixMode(GL_MODELVIEW);
}


void init(void)
{
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Mr Robot");

	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);

	GLfloat globalLight[] = { 0.4f, 0.4f, 0.4f, 1.f };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalLight);

	GLfloat mat_specular0[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_diffuse0[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_ambient0[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess0 = { 100.0 };

	GLfloat mat_specular1[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_diffuse1[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_ambient1[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess1 = { 100.0 };

	GLfloat mat_specular2[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_diffuse2[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_ambient2[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess2 = { 100.0 };


	GLfloat light_ambient0[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light_diffuse0[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat light_specular0[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position0[] = { 10.0, 10.0, 10.0, 0.0 };

	GLfloat light_ambient1[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light_diffuse1[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat light_specular1[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position1[] = { -10.0, 10.0, 10.0, 0.0 };

	GLfloat light_ambient2[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat light_diffuse2[] = { 0.5, 0.5, 0.5, 1.0 };
	GLfloat light_specular2[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position2[] = { 0.0, -10.0, 10.0, 0.0 };

	glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse0);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular0);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse1);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular1);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position2);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient2);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse2);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular2);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient0);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse0);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess0);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular1);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess1);

	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular2);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess2);



	glEnable(GL_SMOOTH);


	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);

	
	glDepthFunc(GL_LEQUAL);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);
}

void initTexture(void)
{

	// Habilita o uso de textura 
	glEnable(GL_TEXTURE_2D);

	// Define quantas texturas serão usadas no programa 
	glGenTextures(1, texture_id);  // 1 = uma textura;
									
	// Define o número da textura do quad.
	texture_id[BRICK_TEXTURE] = 1001;

	// Define que tipo de textura será usada
	glBindTexture(GL_TEXTURE_2D, BRICK_TEXTURE);

	// carrega a uma imagem TGA 
	image_t temp_image_1;
	tgaLoad((char*)"textures/stone.tga", &temp_image_1, TGA_FREE | TGA_LOW_QUALITY);


}



void drawHead(void)
{
	GLUquadricObj* Head;
	Head = gluNewQuadric();

	
	glPushMatrix();
	glTranslatef(0.0, 6.5, 0.0);
	glScalef(2.0, 1.8, 1.0);
	gluSphere(Head, 1.0, 20, 10);
	glPopMatrix();
}

void drawTorso(void)
{
	GLUquadricObj* Torso;
	Torso = gluNewQuadric();
	glPushMatrix();
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(Torso, 2.0, 2.5, 4.5, 10, 10);
	glPopMatrix();

}

void drawKneck(void)
{
	GLUquadricObj* Kneck;
	Kneck = gluNewQuadric();
	glPushMatrix();
	glTranslatef(0.0, 4.5, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(Kneck, 0.2, 0.2, 0.6, 10, 10);
	glPopMatrix();
}

void drawShoulders(void)
{
	GLUquadricObj* LeftShoulder, * RightShoulder;
	LeftShoulder = gluNewQuadric();
	RightShoulder = gluNewQuadric();

	glPushMatrix();
	glTranslatef(-2.2, 4.2, 0.0);
	gluSphere(LeftShoulder, 0.8, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(2.2, 4.2, 0.0);
	gluSphere(RightShoulder, 0.8, 10, 10);
	glPopMatrix();



}

void drawUpperArms(void)
{
	GLUquadricObj* LeftArm, * RightArm;
	LeftArm = gluNewQuadric();
	RightArm = gluNewQuadric();

	glPushMatrix();
	glTranslatef(3.9, 2.7, 0.0);
	glRotatef(-90.0, 1.0, 1.0, 0.0);
	gluCylinder(RightArm, 0.48, 0.6, 2.0, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-3.9, 2.7, 0.0);
	glRotatef(-90.0, 1.0, -1.0, 0.0);
	gluCylinder(LeftArm, 0.48, 0.6, 2.0, 10, 10);
	glPopMatrix();


}

void drawElbows(void)
{
	GLUquadricObj* LeftElbow, * RightElbow;
	LeftElbow = gluNewQuadric();
	RightElbow = gluNewQuadric();

	glPushMatrix();
	glTranslatef(-4.0, 2.5, 0.0);
	gluSphere(LeftElbow, 0.6, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(4.0, 2.5, 0.0);
	gluSphere(RightElbow, 0.6, 10, 10);
	glPopMatrix();

}

void drawLowerArms(void)
{
	GLUquadricObj* LeftArm, * RightArm;
	LeftArm = gluNewQuadric();
	RightArm = gluNewQuadric();

	glPushMatrix();
	glTranslatef(4.05, 0.1, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(RightArm, 0.40, 0.40, 2.0, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-4.05, 0.1, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(LeftArm, 0.40, 0.40, 2.0, 10, 10);
	glPopMatrix();
}

void drawUpperLegs(void)
{
	GLUquadricObj* LeftLeg, * RightLeg;
	LeftLeg = gluNewQuadric();
	RightLeg = gluNewQuadric();

	glPushMatrix();
	glTranslatef(1.38, -2.25, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(RightLeg, 0.48, 0.6, 3.0, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.38, -2.25, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(LeftLeg, 0.48, 0.6, 3.0, 10, 10);
	glPopMatrix();
}

void drawKnee(void)
{
	GLUquadricObj* LeftElbow, * RightElbow;
	LeftElbow = gluNewQuadric();
	RightElbow = gluNewQuadric();

	glPushMatrix();
	glTranslatef(-1.38, -2.5, 0.0);
	gluSphere(LeftElbow, 0.7, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.38, -2.5, 0.0);
	gluSphere(RightElbow, 0.7, 10, 10);
	glPopMatrix();

}

void drawLowerLegs(void)
{
	GLUquadricObj* LeftLeg, * RightLeg;
	LeftLeg = gluNewQuadric();
	RightLeg = gluNewQuadric();

	glPushMatrix();
	glTranslatef(1.38, -6.0, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(RightLeg, 0.40, 0.40, 3.0, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1.38, -6.0, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(LeftLeg, 0.40, 0.40, 3.0, 10, 10);
	glPopMatrix();
}

void drawFeet(void)
{
	GLUquadricObj* LeftFoot, * RightFoot;
	LeftFoot = gluNewQuadric();
	RightFoot = gluNewQuadric();

	glPushMatrix();
	glTranslatef(-1.38, -6.8, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(RightFoot, 0.55, 0.45, 0.8, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1.38, -6.8, 0.0);
	glRotatef(-90.0, 1.0, 0.0, 0.0);
	gluCylinder(LeftFoot, 0.55, 0.45, 0.8, 10, 10);
	glPopMatrix();


}

void drawRobot(void)
{
	glEnable(GL_TEXTURE_GEN_S);
	glEnable(GL_TEXTURE_GEN_T);

	
	glLoadIdentity();
	glColor3f(1.0, 0.0, 0.0);

	glLoadIdentity();

	
	glPushMatrix();

	glBindTexture(GL_TEXTURE_2D, BRICK_TEXTURE);

	glTranslatef(0.0, 0.0, 0.0);
	glRotatef(angle, 0.0, 1.0, 0.0);
	drawTorso();
	drawKneck();
	drawHead();
	drawShoulders();
	drawUpperArms();
	drawElbows();
	drawLowerArms();
	drawUpperLegs();
	drawKnee();
	drawLowerLegs();
	drawFeet();
	glPopMatrix();



}

void Display(void)
{
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-10.0, 10, -10, 10, -10, 10);

	glMatrixMode(GL_MODELVIEW);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	drawRobot();

	glutSwapBuffers();

}



int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	init();
	glutReshapeFunc(myReshape);
	glutKeyboardFunc(callKeyboard);
	initTexture();
	glutDisplayFunc(Display);
	
	

	glutMainLoop();


}