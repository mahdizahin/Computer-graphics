#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <Math.h>



void init(void)
{
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess[] = { 50.0 };
GLfloat light_position[] = { 1.0, 1.5, 1.0, 0.0 };

GLfloat white_light[] = { 0.0, 1.0, 0.5, 1.0 };
GLfloat lmodel_ambient[] = { 0.1, 0.6, 0.1, 1.0 };

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

glEnable(GL_DEPTH_TEST);
}

void init_teapot(void)
{

glDisable(GL_LIGHTING);
GLfloat mat_specular1[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess1[] = { 50.0 };
GLfloat light_position1[] = { .4, .2, .8, 0.0 };

GLfloat white_light1[] = { .4, 0.0, 1.0, 0.0 };
GLfloat lmodel_ambient1[] = { 0.1, 0.6, 0.1, 1.0 };

glClearColor(0.0, 0.0, 0.0, 0.0);

glShadeModel(GL_SMOOTH);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular1);
glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess1);

glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light1);
glLightfv(GL_LIGHT0, GL_SPECULAR, white_light1);
glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient1);

glEnable(GL_LIGHTING);
glEnable(GL_LIGHT1);

glEnable(GL_DEPTH_TEST);

}

void init_torus(void)
{

glDisable(GL_LIGHTING);
GLfloat mat_specular1[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess1[] = { 50.0 };
GLfloat light_position1[] = { 0.0, 1.0, 1.0, 0.0 };

GLfloat white_light1[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat lmodel_ambient1[] = { 0.1, 0.1, 0.1, 1.0 };

glClearColor(0.0, 0.0, 0.0, 0.0);

glShadeModel(GL_SMOOTH);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular1);
glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess1);

glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light1);
glLightfv(GL_LIGHT0, GL_SPECULAR, white_light1);
glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient1);

glEnable(GL_LIGHTING);
glEnable(GL_LIGHT1);

glEnable(GL_DEPTH_TEST);

}

void init_cone(void)
{

glDisable(GL_LIGHTING);
GLfloat mat_specular1[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess1[] = { 50.0 };
GLfloat light_position1[] = { 0.0, 1.0, 1.0, 0.0 };

GLfloat white_light1[] = { 0.0, 1.0, 1.0, 1.0 };
GLfloat lmodel_ambient1[] = { 0.1, 0.1, 0.1, 1.0 };

glClearColor(0.0, 0.0, 0.0, 0.0);

glShadeModel(GL_SMOOTH);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular1);
glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess1);

glLightfv(GL_LIGHT0, GL_POSITION, light_position1);
glLightfv(GL_LIGHT0, GL_DIFFUSE, white_light1);
glLightfv(GL_LIGHT0, GL_SPECULAR, white_light1);
glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient1);

glEnable(GL_LIGHTING);
glEnable(GL_LIGHT1);

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
	init();
	glTranslatef(1, -3.0, 0.0);
	glRotatef(0, 0.0, 1.0, 0.0);
	glutSolidSphere( 2.5,30,40);
	//glDisable(GL_LIGHTING);
	glPopMatrix();



    glPushMatrix();

	init_teapot();
	glTranslatef(10.0, 4.0, 0.0);
	glRotatef(10, 1.0, 0.0, 0.0);
	glutSolidTeapot(1.5);
	//glDisable(GL_LIGHT1);
	glPopMatrix();

    glPushMatrix();
	init_torus();
	glTranslatef(0.8, 4, 0.0);
	//glRotatef(260, 1.0, 0.0, 0.0);
	glutSolidTorus(.6,1.5,5,10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(7.5, -6.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(1.0, 1.0, 0.0);
	glVertex3f(4.0, 1.0, 0.0);
	glVertex3f(4.0, 4.0, 0.0);
	glVertex3f(1.0, 4.0, 0.0);
	glEnd();
	glPopMatrix();




	glPushMatrix();

	glTranslatef(-12.0, -6.5, 0.0);
	glBegin(GL_LINE_LOOP);

	glVertex3f(1.0, 1.0, 0.0);
	glVertex3f(4.0, 1.0, 0.0);
	glVertex3f(4.0, 4.0, 0.0);
	glVertex3f(1.0, 4.0, 0.0);

	glEnd();
	glPopMatrix();

	glPushMatrix();
	init_cone();
	glTranslatef(-9.0, 5.0, 0.0);
	glRotatef(60, 0.0, 1.0, 1.0);
	glScalef(8,8,8);
	glutSolidCone(.2,.10,4,10);
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
glutInitWindowSize(920, 600);
glutCreateWindow("MOVING WORLD WITH LIGHT");
initRendering();
//init();
glutDisplayFunc(drawScene);
glutReshapeFunc(handleResize);
glutInitWindowSize(1280,1080 );
glutInitWindowPosition(720, 500);
glutTimerFunc(25, update, 0);
glutMainLoop();
return 0;
}
