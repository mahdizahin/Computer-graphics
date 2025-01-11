#include <stdio.h>
#include <GL/glut.h>

void myDisplay(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(0.0, 1.0, 0.0,0.50);

    glBegin(GL_POLYGON);
    glVertex2i(50,100);
    glVertex2i(300, 100);
    glVertex2i(150, 300);

    glEnd();

    glColor4f(1.0, 1.0, 0.0,0.60);

    glBegin(GL_POLYGON);
    glVertex2i(20,50);
    glVertex2i(400, 100);
    glVertex2i(200, 400);

    glEnd();
    glFlush ();
}
void myInit (void)
{
    //glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    gluOrtho2D(-640.0, 640.0, -480.0, 480.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (640, 480);
    glutInitWindowPosition (100, 150);
    glutCreateWindow ("Lab 1");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();

    return 0;
}

