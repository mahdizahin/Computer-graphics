#include <windows.h>
#include <GL/glut.h>


void initGL() {

    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
}


void display() {
    glClear(GL_COLOR_BUFFER_BIT);


//b1
     glBegin(GL_POLYGON);
     glColor3ub(255,255,255);
     glVertex2f(1,1); //A
     glVertex2f(1,2); //B
     glVertex2f(2,2);//I
     glVertex2f(2,1);//J
     glEnd();

//yello

     glBegin(GL_POLYGON);

     glColor3ub(0,0,0);
       glVertex2f(2,2);//I
       glVertex2f(2,1);//J
        glVertex2f(3,1);//K
        glVertex2f(3,2);//L

     glEnd();


// 3

     glBegin(GL_POLYGON);

     glColor3ub(255,255,255);
    glVertex2f(3,1);//K
    glVertex2f(3,2);//L
     glVertex2f(4,2); //S
     glVertex2f(4,1); //T


     glEnd();

     //green
     glBegin(GL_POLYGON);
  glColor3ub(0,0,0);
     glVertex2f(4,2); //S
     glVertex2f(4,1); //T
     glVertex2f(5,1); //U
     glVertex2f(5,2);//V
     glEnd();

        //green
     glBegin(GL_POLYGON);
      glColor3ub(0,0,0);
     glVertex2f(1,2); //B
glVertex2f(1,3);//C
 glVertex2f(2,3);//H
glVertex2f(2,2); //I
     glEnd();
     //

     glBegin(GL_POLYGON);

   glColor3ub(255,255,255);
glVertex2f(2,3);//H
glVertex2f(2,2); //I
glVertex2f(3,2); //L
glVertex2f(3,3); //M


     glEnd();

     //

     glBegin(GL_POLYGON);

 glColor3ub(0,0,0);
glVertex2f(3,2); //L
glVertex2f(3,3); //M
glVertex2f(4,3);//R
glVertex2f(4,2);//S

     glEnd();

     //b8
     glBegin(GL_POLYGON);
   glColor3ub(255,255,255);
     glVertex2f(4,3);//R
glVertex2f(4,2);//S
     glVertex2f(5,2);//V
glVertex2f(5,3);//W
     glEnd();

     //b9
     glBegin(GL_POLYGON);
 glColor3ub(255,255,255);
    glVertex2f(1,3);//C
glVertex2f(1,4);//D
  glVertex2f(2,4);//G
glVertex2f(2,3);//H
     glEnd();

     //b1
     glBegin(GL_POLYGON);
  glColor3ub(0,0,0);
glVertex2f(2,4);//G
glVertex2f(2,3);//H
    glVertex2f(3,3); //M
glVertex2f(3,4);//N
     glEnd();

     //b1
     glBegin(GL_POLYGON);
    glColor3ub(255,255,255);
glVertex2f(3,3); //M
glVertex2f(3,4);//N
   glVertex2f(4,4); //Q
glVertex2f(4,3);//R
     glEnd();

     //b12
     glBegin(GL_POLYGON);
 glColor3ub(0,0,0);
glVertex2f(4,4); //Q
glVertex2f(4,3);//R
glVertex2f(5,3);//W
glVertex2f(5,4); //X
     glEnd();

     //b13
     glBegin(GL_POLYGON);
 glColor3ub(0,0,0);
     glVertex2f(1,4);//D
glVertex2f(1,5); //E
glVertex2f(2,5); //F
glVertex2f(2,4);//G
     glEnd();

     //b1
     glBegin(GL_POLYGON);
   glColor3ub(255,255,255);
glVertex2f(2,5); //F
glVertex2f(2,4);//G
glVertex2f(3,4);//N
glVertex2f(3,5);//O
     glEnd();

     //b1
     glBegin(GL_POLYGON);
 glColor3ub(0,0,0);
glVertex2f(3,4);//N
glVertex2f(3,5);//O
glVertex2f(4,5); //P
glVertex2f(4,4); //Q
     glEnd();

          //b1
     glBegin(GL_POLYGON);
glColor3ub(255,255,255);

glVertex2f(4,5); //P
glVertex2f(4,4); //Q
glVertex2f(5,4); //X
glVertex2f(5,5); //Y
     glEnd();


    glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Rainbow Flag");
    glutInitWindowSize(900, 720);
    gluOrtho2D(0,6,0,6);
    glutInitWindowPosition(100, 100);
    glutDisplayFunc(display);
    initGL();
    glutMainLoop();
}
