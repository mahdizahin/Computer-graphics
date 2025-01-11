
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>


void myInit()
{
    glClearColor(0.0,0.0,0.0,0.0);
    glColor3f(1.0,0.0,0.0);
    glPointSize(8.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	glShadeModel(GL_SMOOTH);
    gluOrtho2D(0.0,1.0,0.0,1.0);
}
void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);


	glColor3f(1.0,0.0,0.0);
	for(float y=0.0;y<=1.0;y+=0.05)
	{

		for(float x=0.0;x<=1.0;x+=0.05)
		{
			for(float z=0.0;z<=1.0;z+=0.05)
			{

			glColor3f(y,x,z);
			glBegin(GL_QUADS);
			glVertex2f(x, y);
			glVertex2f(x+0.05, y);
			glVertex2f(x+.05, y+.05);
			glVertex2f(x, y+.05);

			glEnd();
			glFlush();
			}
		}

	}



	glFlush();
}



int main(int argc, char *argv[])
{
	//takeInput();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,150);
    glutCreateWindow("color_rectangle");
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop();
    return 0;
}
