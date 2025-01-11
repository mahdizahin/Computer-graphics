#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
//#define DEG2RAD 3.14159/180.0
const float DEG2RAD = 3.14159/180.0;
void drawEllipse(float xradius, float yradius);


void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glColor3f(1.0, 0.0, 0.0);
	//glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
	glColor3f(1.0, 0.0, 0.0);
}

float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;
float _angle_2 = 90;
float i = 0.0f;


void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -3.0); //Move forward 5 units

//

//    glPushMatrix();
 //glColor3f(0.0,0.0,0.0);
//    glTranslatef(-1.0,0.60,0.0);
//    glRotatef(_angle,0.0,1.0,0.0);
//    glutWireSphere(.20,10,20);
//    glPopMatrix();
//
//
//    glPushMatrix();
//    glTranslatef(0.0,0.40,0.0);
//    glColor3f(0.0,0.0,0.0);
//    glBegin(GL_POLYGON);
//	for(int i=0;i<200;i++)
//	{
//		float pi=3.1416;
//		float A=(i*2*pi)/50;
//		float r=0.1;
//		float x = r * cos(A);
//		float y = r * sin(A);
//		glVertex2f(x,y );
//	}
//	glEnd();
//    glPopMatrix();
    glPushMatrix();
    glColor3f(1.50,0.0,1.20);
    glTranslatef(0.1,0.88,0.0);         //Head circle
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidSphere(.14,10,5); //(GLdouble radius,GLint slices, GLint stacks);
    glPopMatrix();


    /////////////////////////////////////////

    glPushMatrix();
    glColor3f(0.0,0.0,1.0);
    glTranslatef(0.0,0.1,0.0);
   // glRotatef(_angle,0.0,1.0,0.0);
    glutSolidSphere(.35,20,20); //(GLdouble radius,GLint slices, GLint stacks);
    glPopMatrix();

    glPushMatrix();
    glNormal3f(-1.0f, 0.0f, -1.0f);//n1
    glColor3f(0.7,0.0,0.0);
    glTranslatef(0.0,0.10,0.0);
    glRotatef(20,1.0,0.0,0.0);
    glRotatef(90,1.0,0.0,0.0);
    //glRotatef(_angle,0.0,0.0,1.0);
     glNormal3f(-1.0f, 0.0f, -1.0f);//n1
    glutSolidTorus(.08, .3, 35, 35); //middle circle


    glPopMatrix();


 glNormal3f(-1.0f, 0.0f, -1.0f);//n1
    glPushMatrix();
    glColor3f(1.50,0.0,1.20);
    glTranslatef(-0.45,0.1,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidSphere(.14,10,5); //(Left hand
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.50,0.0,1.20);
    glTranslatef(0.7,0.2,0.0);

    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidSphere(.14,10,5); //(right hand

    glColor3f(1.0,1.0,0.0);
    glTranslatef(0.0,0.29,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidSphere(.2,10,5);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.50,0.0,1.20);
    glTranslatef(-0.15,-0.45,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidSphere(.14,10,5); //(Left leg
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.50,0.0,1.20);
    glTranslatef(0.09,-0.45,0.0);
    //glRotatef(_angle,0.0,1.0,0.0);
    glutSolidSphere(.15,10,6); //( right leg
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
    glTranslatef(0.0,0.30,0.0);
    GLUquadricObj *quadratic;
    quadratic = gluNewQuadric();
    glRotatef(65,0.0,1.0,-1.0);
//void gluCylinder(GLUquadric*  quad,  GLdouble  base,  GLdouble  top,  GLdouble  height,  GLint  slices,  GLint  stacks);
    gluCylinder(quadratic,0.06,0.06,0.6,10,10);

    glRotatef(60,0.0,-1.0,-1.4);
    glTranslatef(0.14,0.55,0.0);
    gluCylinder(quadratic,0.06,0.06,0.17,10,10);

    glTranslatef(0.06,-1.0,0.0);
    gluCylinder(quadratic,0.05,0.03,0.17,10,10);

//    glRotatef(90,0.0,1.0,0.0);
//    glTranslatef(0.9,-0.8,0.0);
//    gluCylinder(quadratic,0.035,0.035,0.17,10,10);

    glPopMatrix();

     glPushMatrix();
    glColor3f(0.9,.9,.9);
    glTranslatef(-0.15,-0.06,0.0);
    GLUquadricObj *quadrati;
    quadrati = gluNewQuadric();
    glRotatef(90,1.0,0.0,0.0);
    gluCylinder(quadrati,0.05,0.05,0.3,10,10);
    glTranslatef(0.25,-0.2,0.0);
    gluCylinder(quadrati,0.05,0.05,0.3,10,10);

    glPopMatrix();


 glPushMatrix();
 glClear(GL_DEPTH_BUFFER_BIT);
    glColor3f(.70,0.70,.70);
    glTranslatef(-0.13,-0.01,0.0);
    //glRotatef(15,1.0,1.0,0.0);
    glRotatef(190,0.0,1.0,-0.1);
    // glRotatef(10,0.0,1.0,1.0);          //belt
    glutWireCube(.09); //(GLdouble size)
    glColor3f(1.0,0.0,.0);
    glutSolidCube(.03);
    glPopMatrix();


//

    glPushMatrix();

    glColor3f(.70,0.70,.70);
    glTranslatef(0.0,0.60,0.0);
    glRotatef(15,1.0,1.0,0.0);
    glRotatef(140,0.0,1.0,0.0);         //head
    glutSolidCube(.40); //(GLdouble size)
    glPopMatrix();


    glPushMatrix();
    glEnable(GL_DEPTH_TEST);
    glClear(GL_DEPTH_BUFFER_BIT);
    glColor3f(1.25,1.90,1.250);

    glTranslatef(0,0.6,0);        //eyes
    drawEllipse(0.04, 0.1);
    glTranslatef(-0.18,0.0,0.0);
    drawEllipse(0.04, 0.1);

     glRotatef(60,0.0,1.0,0.0);
    //glutWireCube(.20);
    glTranslatef(-0.1,0.14,0.0);      //eyebrue
    drawEllipse(0.15, 0.03);


    glTranslatef(0.6,0.13,0.0);
    glRotatef(60,0.0,1.0,0.0);
    drawEllipse(0.24, 0.04);

	glFlush();
    glPopMatrix();


	glutSwapBuffers();

}
void drawEllipse(float xradius, float yradius)
{
	glBegin(GL_POLYGON);

	for(int i=0; i < 360; i++)
	{
		 //convert degrees into radians
		float degInRad = i*DEG2RAD;
		glVertex2f(cos(degInRad)*xradius,sin(degInRad)*yradius);
	}
	glEnd();
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
	glDisable (GL_DEPTH_TEST);
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

