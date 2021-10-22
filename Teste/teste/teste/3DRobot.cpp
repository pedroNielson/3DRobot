#include <GL/glut.h>
#include <GL/GLU.h>

using namespace std;

void myReshape(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w <= h)
		glOrtho(-10.0, 10.0, -10.0 * (GLfloat)h / (GLfloat)w, 10.0 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	else
		glOrtho(-10.0 * (GLfloat)w / (GLfloat)h, 10.0 * (GLfloat)w / (GLfloat)h, 0.0, 10.0, -10.0, 10.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void init(void)
{
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(800, 600);
	glutCreateWindow("Mr Robot");
	
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glEnable(GL_DEPTH_TEST);


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
	GLUquadricObj* LeftShoulder, *RightShoulder;
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
	GLUquadricObj* LeftLeg, *RightLeg;
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
	glLoadIdentity();
	glPushMatrix();
		glTranslatef(0.0, 0.0, 0.0);
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
	glOrtho(-10, 10, -10, 10, -10, 10);
	
	glMatrixMode(GL_MODELVIEW);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glColor3f(0.4, 0.4, 0.4);


	
	drawRobot();
	glutSwapBuffers();

}




int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	init();
	glutReshapeFunc(myReshape);
	glutDisplayFunc(Display);


	glutMainLoop();


}