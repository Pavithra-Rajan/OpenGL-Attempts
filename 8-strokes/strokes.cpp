#include <GL/gl.h>
#include <iostream>
#include <GL/glut.h>
using namespace std;

void keyboard(unsigned char key, int x, int y) {
    switch (key) 
    {
        // To reset the canvas
        case 'r':
        glClearColor(1.0, 1.0, 1.0, 0.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
        break;
    }
}

void glutMotion(int x, int y) 
{
    //cout << "x: " << x << " y: " << y << endl;
    float H = glutGet(GLUT_WINDOW_HEIGHT);
    float W = glutGet(GLUT_WINDOW_WIDTH);
    float X = ((float)x - W / 2) / (W / 2);
    float Y = ((H - (float)y) - H / 2) / (H / 2);

    glColor3f(0.0, 0.0, 0.0);
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2f(X, Y);
    glEnd();
    glFlush();
}

void mouse(int button, int state, int x, int y) 
{
    if (0 and button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) 
    {
        float H = glutGet(GLUT_WINDOW_HEIGHT);
        float W = glutGet(GLUT_WINDOW_WIDTH);
        float X = ((float)x - W / 2) / (W / 2);
        float Y = ((H - (float)y) - H / 2) / (H / 2);

        glColor3f(0.0, 0.0, 0.0);
        glPointSize(5);
        glBegin(GL_POINTS);
        glVertex2f(X, Y);
        glEnd();
        glFlush();
  }
}

void renderFunction() 
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 1.0);
    glPointSize(5.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

    glFlush();
}
int main (int argc, char** argv) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 200);
    glutCreateWindow("Mouse Strokes");

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(glutMotion);
    glutDisplayFunc(renderFunction);
    glutMainLoop();
    return 0;
}