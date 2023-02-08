#include <GL/glut.h>
#include <stdio.h>

GLfloat strip[4][2];
int n;

void readFile()
{
    FILE *fin;
    fin = fopen("strip.txt", "r");
    fscanf(fin, "%d", &n);
    for (int i = 0; i < n; i++)
    {
        fscanf(fin, "%f%f", &strip[i][0], &strip[i][1]);
    }
    fclose(fin);
}

void display()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    
    glBegin(GL_QUAD_STRIP);
    for (int i = 0; i < n; i++)
    {
        glVertex2fv(strip[i]);
    }
    glEnd();

    glFlush();
}

int main(int argc, char** argv)
{
    readFile();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rectangular Strip");

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
