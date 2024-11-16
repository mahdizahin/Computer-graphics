#include <windows.h>
#include <GL/glut.h>


void initGL() {

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);


//red

     glBegin(GL_POLYGON);

     glColor3ub(255,0,0);
     glVertex2f(1,1); //A
     glVertex2f(11,1); //B
     glVertex2f(11,2);//C
     glVertex2f(1,2);//D

     glEnd();

//yello

     glBegin(GL_POLYGON);

     glColor3ub(247,255,0);
       glVertex2f(1,2);//D

glVertex2f(11,2);//C
glVertex2f(11,3);//F
glVertex2f(1,3);//E

     glEnd();


// 3

     glBegin(GL_POLYGON);

     glColor3ub(255,162,0);
   glVertex2f(1,3);//E
glVertex2f(11,3);//F
     glVertex2f(11,4); //G
     glVertex2f(1,4); //H


     glEnd();

     //green

     glBegin(GL_POLYGON);

     glColor3ub(0,200,0);
     glVertex2f(11,4); //G
     glVertex2f(1,4); //H
     glVertex2f(1,5);//I
     glVertex2f(11,5);// J



     glEnd();

     //sky blue

     glBegin(GL_POLYGON);

     glColor3ub(7,179,254);
     glVertex2f(1,5);//I
     glVertex2f(11,5);// J
     glVertex2f(11,6); //k
     glVertex2f(1,6);//L


     glEnd();
     //

     glBegin(GL_POLYGON);

     glColor3ub(116,159,243);
     glVertex2f(11,6); //k
     glVertex2f(1,6);//L
     glVertex2f(1,7);//M
     glVertex2f(11,7);//N


     glEnd();

     //

     glBegin(GL_POLYGON);

     glColor3ub(180,129,232);
     glVertex2f(1,7);//M
     glVertex2f(11,7);//N
     glVertex2f(11,8);//0
     glVertex2f(1,8);//p

     glEnd();

    glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Rainbow Flag");
    glutInitWindowSize(900, 720);
    gluOrtho2D(-1,15,-1,15);
    glutInitWindowPosition(100, 100);
    glutDisplayFunc(display);
    initGL();
    glutMainLoop();
}
