// color_cube.c
#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

GLfloat vertices[] = {
    -1.0f, -1.0f, -1.0f, // 0
    1.0f, -1.0f, -1.0f,  // 1
    1.0f, 1.0f, -1.0f,   // 2
    -1.0f, 1.0f, -1.0f,  // 3
    -1.0f, -1.0f, 1.0f,  // 4
    1.0f, -1.0f, 1.0f,   // 5
    1.0f, 1.0f, 1.0f,    // 6
    -1.0f, 1.0f, 1.0f    // 7
};

GLfloat normals[] = {
    -1.0f, -1.0f, -1.0f,
    1.0f, -1.0f, -1.0f,
    1.0f, 1.0f, -1.0f,
    -1.0f, 1.0f, -1.0f,
    -1.0f, -1.0f, 1.0f,
    1.0f, -1.0f, 1.0f,
    1.0f, 1.0f, 1.0f,
    -1.0f, 1.0f, 1.0f};

GLfloat colors[] = {
    0.0f, 0.0f, 0.0f, // 0 black
    1.0f, 0.0f, 0.0f, // 1 red
    1.0f, 1.0f, 0.0f, // 2 yellow
    0.0f, 1.0f, 0.0f, // 3 green
    0.0f, 0.0f, 1.0f, // 4 blue
    1.0f, 0.0f, 1.0f, // 5 magenta
    1.0f, 1.0f, 1.0f, // 6 white
    0.0f, 1.0f, 1.0f  // 7 cyan
};

// Draw the cube as 6 quads (4 indices each) -- order matches vertices above.
GLubyte cubeIndices[] = {
    0, 1, 2, 3, // back face (z = -1)
    4, 5, 6, 7, // front face (z = +1)
    0, 4, 7, 3, // left face (x = -1)
    1, 5, 6, 2, // right face (x = +1)
    3, 2, 6, 7, // top face (y = +1)
    0, 1, 5, 4  // bottom face (y = -1)
};

static GLfloat theta[] = {0.0f, 0.0f, 0.0f};
static GLint axis = 2;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // apply rotations
    glRotatef(theta[0], 1.0f, 0.0f, 0.0f);
    glRotatef(theta[1], 0.0f, 1.0f, 0.0f);
    glRotatef(theta[2], 0.0f, 0.0f, 1.0f);

    // Draw using client arrays: vertices, normals, colors
    glDrawElements(GL_QUADS, 24, GL_UNSIGNED_BYTE, cubeIndices);

    glutSwapBuffers();
}

void mouse(int btn, int state, int x, int y)
{
    if (state != GLUT_DOWN)
        return;
    if (btn == GLUT_LEFT_BUTTON)
        axis = 0; // rotate around X
    else if (btn == GLUT_RIGHT_BUTTON)
        axis = 1; // rotate around Y
    else if (btn == GLUT_MIDDLE_BUTTON)
        axis = 2; // rotate around Z
}

void spincube(void)
{
    theta[axis] += 2.0f;
    if (theta[axis] > 360.0f)
        theta[axis] -= 360.0f;
    glutPostRedisplay();
}

void myReshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w <= h)
    {
        glOrtho(-2.0, 2.0, -2.0 * (GLfloat)h / (GLfloat)w,
                2.0 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
    }
    else
    {
        glOrtho(-2.0 * (GLfloat)w / (GLfloat)h,
                2.0 * (GLfloat)w / (GLfloat)h, -2.0, 2.0, -10.0, 10.0);
    }

    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("color cube");

    glutReshapeFunc(myReshape);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutIdleFunc(spincube);

    glEnable(GL_DEPTH_TEST);

    // Enable client-side capability and set pointers
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);

    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glNormalPointer(GL_FLOAT, 0, normals);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    glutMainLoop();
    return 0;
}