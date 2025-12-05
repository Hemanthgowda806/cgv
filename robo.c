#include <stdio.h>
#include <GL/glut.h>
#define SQUARE 1
void display()
{
    glBegin(GL_POLYGON);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glEnd();
    glNewList(SQUARE, GL_COMPILE_EXECUTE);
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.2, 0.3);
    glVertex2f(-0.3, 0.3);
    glVertex2f(-0.3, 0.2);
    glVertex2f(-0.2, 0.2);
    glEnd();
    glEndList();
    glCallList(SQUARE);
    glTranslatef(0.5, 0.0, 0.0);
    glCallList(SQUARE);
    glTranslatef(-0.25, -0.3, 0.0);
    glCallList(SQUARE);
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(0.55, 0.2, 0.0);
    glCallList(SQUARE);
    glTranslatef(-1.1, 0., 0.0);
    glCallList(SQUARE);
    glFlush();
}
void main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutCreateWindow("square");
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50, 50);
    glutDisplayFunc(display);
    glutMainLoop();
}
