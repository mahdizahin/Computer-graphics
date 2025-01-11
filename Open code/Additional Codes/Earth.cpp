#include <iostream>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <Math.h>

void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = 30.0;
float _cameraAngle = 5.0;

void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(-_cameraAngle, 0.0, 1.0, 0.0);
	glTranslatef(0.0, 0.0, -20.0);




    glPushMatrix();
	glColor3f(0,1,1);
	glTranslatef(3.0, 1.0, 0.0);
	glRotatef(0, 0.0, 1.0, 0.0);
	glRotatef(_angle, 0.0, 1.0, 0.0);
	glutWireSphere( 2,30,40);
	glBegin(GL_TRIANGLES);
	glEnd();
	glPopMatrix();



    glPushMatrix();
    glColor3f(1,0,1);
	glTranslatef(0, 1.0, 0.0);
	glRotatef(250, 1.0, 0.0, 0.0);
	glRotatef(_angle, 0.0, 0.0, 1.0);
	glutWireCone(2, 5, 30, 30);
	glBegin(GL_TRIANGLES);
	glEnd();
	glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
	glTranslatef(0, 3, 0.0);
	glRotatef(260, 1.0, 0.0, 0.0);
	glRotatef(_angle, 0.0, 0.0, -1.0);
	glutWireTorus(.7,1.8,50,40);
	glBegin(GL_TRIANGLES);
	glEnd();
	glPopMatrix();



	glutSwapBuffers();
}

void update(int value) {
	_angle += 2.0f;
	if (_angle > 360) {
		_angle -= 360;
	}
	glutPostRedisplay();
	glutTimerFunc(20, update, 0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutCreateWindow("TEAPOT");
	initRendering();
	glutDisplayFunc(drawScene);
	glutReshapeFunc(handleResize);
	glutTimerFunc(2, update, 0);
	glutMainLoop();
	return 0;
}
