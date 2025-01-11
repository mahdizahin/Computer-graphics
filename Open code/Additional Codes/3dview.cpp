#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>

void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;
float _angle_2 = 90;
float i = 0.0f;


void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//	glColor3f(1.0, 0.0, 0.0);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -3.0); //Move forward 5 units

//
	glPushMatrix();

    glPushMatrix();
    glColor3f(1.0,1,1);
    //glColor3f(0.0,.5,.5);
    glTranslatef(-1.0,0.60,0.0);
    glScalef(.5,.5,0);
    glRotatef(_angle,0.0,1.0,0.0);
    glutWireSphere(.20,20,20);
    glPopMatrix();


    glPushMatrix();
    glColor3f(1.50,0.50,0.20);
    glTranslatef(-.35,0.60,0.0);
    glRotatef(_angle,0.0,1.0,0.0);
    glutSolidSphere(.20,20,20); //(GLdouble radius,GLint slices, GLint stacks);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1,1.0,1.0);

    glTranslatef(.15,0.60,0.0);
    glRotatef(_angle,0.0,1.0,0.0);
    glutWireCube(.3);
    glPopMatrix();


    glPushMatrix();
    glColor3f(1.0,0.50,.50);
    glTranslatef(.65,0.60,0.0);
    glRotatef(_angle,0.0,1.0,0.0);
    glutSolidCube(.25); //(GLdouble size)
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,0.50,1.0);
    glTranslatef(0.0,-0.20,0.0);
    glRotatef(-60,1.0,0.0,0.0);
    glRotatef(_angle,1.0,1.0,0.0);
    glutWireCone(.25,.50,15,15); //(GLdouble base, GLdouble height,GLint slices, GLint stacks);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.25,0.90,.250);
    glTranslatef(-0.90,-0.20,0.0);
    //glRotatef(-90,1.0,1.0,0.0);
    glRotatef(_angle,1.0,1.0,0.0);
    glutWireTorus(.20, .40, 20, 20); //(GLdouble innerRadius,GLdouble outerRadius,GLint nsides, GLint rings);
    glPopMatrix();









	glPopMatrix();
	glutSwapBuffers();
}

void update(int value) {
	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(900, 600);

	//Create the window
	glutCreateWindow("Transformations and Timers - videotutorialsrock.com");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);

	glutTimerFunc(25, update, 0); //Add a timer

	glutMainLoop();
	return 0;
}

