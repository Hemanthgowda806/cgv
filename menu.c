
#include <stdio.h>
#include <GL/glut.h>
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
}
void draw()
{
    glBegin(GL_POLYGON);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glEnd();
    glFlush();
}
void myDemo(int id)
{
    switch (id)
    {
    case 1:
        exit(0);
        break;
    case 2:
        draw();
        break;
    }
}
void main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glutCreateWindow("square");
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50, 50);
    glutCreateMenu(myDemo);
    glutAddMenuEntry("quit", 1);
    glutAddMenuEntry("draw", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(display);
    glutMainLoop();
}