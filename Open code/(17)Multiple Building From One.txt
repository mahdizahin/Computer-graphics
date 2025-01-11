#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <math.h>
void circle(float radius, float xc, float yc, float r, float g, float b)
{
    glBegin(GL_POLYGON);// Draw a Red 1x1 Square centered at origin
	for(int i=0;i<200;i++)
        {
            glColor3f(r,g,b);
            float pi=3.1416;
            float A=(i*2*pi)/200;
            float r=radius;
            float x = r * cos(A);
            float y = r * sin(A);
            glVertex2f(x+xc,y+yc);
        }
	glEnd();

}
void line(float r, float g, float b){
    glColor3ub(r,g,b);
    glBegin(GL_POLYGON);
    glVertex2f(-6,-6);
    glVertex2f(6,-6);
    glVertex2f(6,9.6);
    glVertex2f(-6,9.6);
    glEnd();
    glColor3ub(0, 0, 0);
    glLineWidth(4);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-6,-6);
    glVertex2f(-6,0);
    glVertex2f(-6,2.4);
    glVertex2f(-6,4.8);
    glVertex2f(-6,7.21);
    glVertex2f(-6,9.6);
    glVertex2f(6,9.6);
    glVertex2f(6,7.21);
    glVertex2f(6,4.8);
    glVertex2f(6,2.4);
    glVertex2f(6,0);
    glVertex2f(6,-6);
    glEnd();
    glColor3ub(255,0,0);
    glBegin(GL_POLYGON);
    glVertex2f(-2,-6);
    glVertex2f(2,-6);
    glVertex2f(2,-2);
    glVertex2f(-2,-2);
    glEnd();
    glColor3ub(0, 0, 0);
    glLineWidth(4);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-2,-6);
    glVertex2f(2,-6);
    glVertex2f(2,-2);
    glVertex2f(-2,-2);
    glEnd();

glColor3ub(0,0,0);
glBegin(GL_LINES);
glVertex2f(-6,0);
glVertex2f(6,0);
glEnd();
glColor3ub(0,0,0);
glBegin(GL_LINES);
glVertex2f(-6,2.4);
glVertex2f(6,2.4);
glEnd();
glColor3ub(0,0,0);
glBegin(GL_LINES);
glVertex2f(-6,4.8);
glVertex2f(6,4.8);
glEnd();
glColor3ub(0,0,0);
glBegin(GL_LINES);
glVertex2f(-6,7.21);
glVertex2f(6,7.21);
glEnd();
glColor3ub(0,0,0);
glBegin(GL_LINES);
glVertex2f(-6,9.6);
glVertex2f(6,9.6);
glEnd();

}
void window(){
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(-4,2);
    glVertex2f(-4,0.8);
    glVertex2f(-2,0.8);
    glVertex2f(-2,2);
    glEnd();
    glColor3ub(0, 0, 0);
    glLineWidth(4);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-4,2);
    glVertex2f(-4,0.8);
    glVertex2f(-2,0.8);
    glVertex2f(-2,2);
    glEnd();
}
void window1(){
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(2,2);
    glVertex2f(2,0.8);
    glVertex2f(4,0.8);
    glVertex2f(4,2);
    glEnd();
    glColor3ub(0, 0, 0);
    glLineWidth(4);
    glBegin(GL_LINE_LOOP);
    glVertex2f(2,2);
    glVertex2f(2,0.8);
    glVertex2f(4,0.8);
    glVertex2f(4,2);
    glEnd();
}
void window2(){
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(-4,4.3);
    glVertex2f(-4,3.1);
    glVertex2f(-2,3.1);
    glVertex2f(-2,4.3);
    glEnd();
    glColor3ub(0, 0, 0);
    glLineWidth(4);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-4,4.3);
    glVertex2f(-4,3.1);
    glVertex2f(-2,3.1);
    glVertex2f(-2,4.3);
    glEnd();
}
void window3(){
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(2,4.3);
    glVertex2f(2,3.1);
    glVertex2f(4,3.1);
    glVertex2f(4,4.3);
    glEnd();
    glColor3ub(0, 0, 0);
    glLineWidth(4);
    glBegin(GL_LINE_LOOP);
     glVertex2f(2,4.3);
    glVertex2f(2,3.1);
    glVertex2f(4,3.1);
    glVertex2f(4,4.3);
    glEnd();
}
void window4(){
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(-4,6.8);
    glVertex2f(-4,5.6);
    glVertex2f(-2,5.6);
    glVertex2f(-2,6.8);
    glEnd();
    glColor3ub(0, 0, 0);
    glLineWidth(4);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-4,6.8);
    glVertex2f(-4,5.6);
    glVertex2f(-2,5.6);
    glVertex2f(-2,6.8);
    glEnd();
}
void window5(){
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(2,6.8);
    glVertex2f(2,5.6);
    glVertex2f(4,5.6);
    glVertex2f(4,6.8);
    glEnd();
    glColor3ub(0, 0, 0);
    glLineWidth(4);
    glBegin(GL_LINE_LOOP);
    glVertex2f(2,6.8);
    glVertex2f(2,5.6);
    glVertex2f(4,5.6);
    glVertex2f(4,6.8);
    glEnd();
}
void window6(){
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(-4,9.2);
    glVertex2f(-4,8);
    glVertex2f(-2,8);
    glVertex2f(-2,9.2);
    glEnd();
    glColor3ub(0, 0, 0);
    glLineWidth(4);
    glBegin(GL_LINE_LOOP);
    glVertex2f(-4,9.2);
    glVertex2f(-4,8);
    glVertex2f(-2,8);
    glVertex2f(-2,9.2);
    glEnd();
}
void window7(){
    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(2,9.2);
    glVertex2f(2,8);
    glVertex2f(4,8);
    glVertex2f(4,9.2);
    glEnd();
    glColor3ub(0, 0, 0);
    glLineWidth(4);
    glBegin(GL_LINE_LOOP);
    glVertex2f(2,9.2);
    glVertex2f(2,8);
    glVertex2f(4,8);
    glVertex2f(4,9.2);
    glEnd();
}
void building1(float r, float g, float b)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.3,0.3,0);
    glTranslatef(0,0,0);
    line(r,g,b);
    window();
    window1();
    window2();
    window3();
    window4();
    window5();
    window6();
    window7();
    circle(2 ,0 , -2.35, 0, 0, 0);
    circle(1.96 ,0 , -2.47, 255, 0, 0);
    glPopMatrix();
}

void building2(float r, float g, float b)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.3,0.3,0);
    glTranslatef(15,0,0);
    line(r,g,b);
    window();
    window1();
    window2();
    window3();
    window4();
    window5();
    window6();
    window7();
    circle(2 ,0 , -2.35, 0, 0, 0);
    circle(1.96 ,0 , -2.47, 255, 0, 0);
    glPopMatrix();
}

void building3(float r, float g, float b)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glScalef(0.3,0.3,0);
    glTranslatef(-15,0,0);
    line(r,g,b);
    window();
    window1();
    window2();
    window3();
    window4();
    window5();
    window6();
    window7();
    circle(2 ,0 , -2.35, 0, 0, 0);
    circle(1.96 ,0 , -2.47, 255, 0, 0);
    glPopMatrix();
}
void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);
    building1(100,30,100);
    building2(0,30,100);
    building3(255,30,100);
	glFlush();
	  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(800, 800);                // Initialize GLUT
	glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
	   // Set the window's initial width & height
	glutDisplayFunc(display);
	gluOrtho2D(-10,10,-10,10);// Register display callback handler for window re-paint
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
