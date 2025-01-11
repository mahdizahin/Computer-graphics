#include <iostream>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <Math.h>



void init(void)
{
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess[] = { 50.0 };
GLfloat light_position[] = { 0.0, 0.0, 1.0, 0.0 };

GLfloat white_light[] = { 0.0, 1.0, 0.0, 1.0 };
GLfloat lmodel_ambient[] = { 0.1, 0.20, 0.1, 1.0 };

glClearColor(0.0, 0.0, 0.0, 0.0);

glShadeModel(GL_SMOOTH);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

glLightfv(GL_LIGHT0, GL_POSITION, light_position);
glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light);
glLightfv(GL_LIGHT0, GL_SPECULAR, white_light);
glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);

glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);


/*GLfloat light1_position[] = { 0.0, 1.0, 1.0, 0.0 };
GLfloat white1_light[] = { 0.0, 1.0, 0.0, 1.0 };

glLightfv(GL_LIGHT1, GL_POSITION, light1_position);
glLightfv(GL_LIGHT1, GL_DIFFUSE, white1_light);
glLightfv(GL_LIGHT1, GL_SPECULAR, white1_light);

glEnable(GL_LIGHT1);
*/
glEnable(GL_DEPTH_TEST);
}

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
	glTranslatef(-3.0, -1.0, -20.0);




    glPushMatrix();
	glTranslatef(3.0, 1.0, -2.5);
	glRotatef(0, 0.0, 1.0, 0.0);
	glutSolidSphere( 2,30,40);
	glPopMatrix();



    glPushMatrix();
	glTranslatef(0, 1.0, 0.0);
	glRotatef(250, 1.0, 0.0, 0.0);
	glutSolidCone(2, 5, 30, 30);
	glPopMatrix();

    glPushMatrix();
	glTranslatef(0, 3, 0.0);
	glRotatef(260, 1.0, 0.0, 0.0);
	glutSolidTorus(.6,1.5,50,40);
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
glutCreateWindow("MOVING WORLD WITH LIGHT");
initRendering();
init();
glutDisplayFunc(drawScene);
glutReshapeFunc(handleResize);
glutInitWindowSize(1000, 800);
glutInitWindowPosition(500, 130);
glutTimerFunc(25, update, 0);
glutMainLoop();
return 0;
}
