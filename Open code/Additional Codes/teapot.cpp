#include <iostream>
#include <stdlib.h>
#include <math.h>



#include <GL/glut.h>




//Initializes 3D rendering
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

/*void drw()
{
	i=i+.5;
	glPushMatrix();
	glTranslatef(-i, 0.0, 0.0);
	glutWireTeapot(.15);
	glPopMatrix();
}*/
//Draws the 3D scene
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//	glColor3f(1.0, 0.0, 0.0);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -3.0); //Move forward 5 units

//
	glPushMatrix();
//	glRotatef(_angle, 0.0, 1.0, 0.0);
//	glTranslatef(-.25, 0.0, 0.0);

	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(-.25, 0.0, 0.0);
	glRotatef(_angle, 0.0, 1.0, 0.0);

	//glutSolidTetrahedron();
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 1.0, 1.0);
	glTranslatef(-.75, 0.0, 0.0);
	glRotatef(_angle, 0.0, 1.0, 0.0);
	glutWireTeapot(.15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 1.0, 1.0);
	glTranslatef(.25, 0.0, 0.0);
	glRotatef(_angle, 0.0, 1.0, 0.0);
	glutWireTeapot(.15);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.0, 1.0, 1.0);
	glTranslatef(.75, 0.0, 0.0);
	glRotatef(_angle, 0.0, 1.0, 0.0);
	glutWireTeapot(.15);
	glPopMatrix();


	glPopMatrix();

	glPushMatrix();
//	glRotatef(_angle, 0.0, 1.0, 0.0);
	glTranslatef(0.0, .5, 0.0);

	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(-.25, 0.0, 0.0);
	glRotatef(_angle, 0.0, 1.0, 0.0);
	glutWireTeapot(.15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 1.0, 1.0);
	glTranslatef(-.75, 0.0, 0.0);
	glRotatef(_angle, 0.0, 1.0, 0.0);
	glutWireTeapot(.15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 1.0, 1.0);
	glTranslatef(.25, 0.0, 0.0);
	glRotatef(_angle, 0.0, 1.0, 0.0);
	glutWireTeapot(.15);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.0, 1.0, 1.0);
	glTranslatef(.75, 0.0, 0.0);
	glRotatef(_angle, 0.0, 1.0, 0.0);
	glutWireTeapot(.15);
	glPopMatrix();

	glPopMatrix();


	glPushMatrix();
//	glRotatef(_angle, 0.0, 1.0, 0.0);
	glTranslatef(0.0, -.5, 0.0);

	glPushMatrix();
	glColor3f(0.0, 1.0, 0.0);
	glTranslatef(-.25, 0.0, 0.0);
	glRotatef(_angle, 0.0, 1.0, 0.0);
	glutWireTeapot(.15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(-.75, 0.0, 0.0);
	glRotatef(_angle, 0.0, 1.0, 0.0);
	glutWireTeapot(.15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.0, 1.0, 1.0);
	glTranslatef(.25, 0.0, 0.0);
	glRotatef(_angle, 0.0, 1.0, 0.0);
	glutWireTeapot(.15);
	glPopMatrix();


	glPushMatrix();
	glColor3f(0.0, 0.0, 1.0);
	glTranslatef(.75, 0.0, 0.0);
	glRotatef(_angle, 0.0, 1.0, 0.0);
	glutWireTeapot(.15);
	glPopMatrix();

	glPopMatrix();

	glPushMatrix();

	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(0.0, .85, 0.0);
	glRotatef(_angle, 0.0, 1.0, 0.0);
	glutWireTeapot(.15);
	glPopMatrix();

	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	glTranslatef(0.0, -.85, 0.0);
	glRotatef(_angle, 0.0, 1.0, 0.0);
	glutWireTeapot(.15);
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
