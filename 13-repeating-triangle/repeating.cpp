#include<GL/freeglut.h>
#include<GL/gl.h>
#include<stdio.h>

void drawtriangle(float x1, float y1, float x2, float y2, float x3, float y3)
{
    glColor3f(0.0, 0.0, 0.0);
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
    glEnd();
    glFlush();
}

void drawfigure(float x1, float y1, float x2, float y2, float x3, float y3, int counter) 
{
    float x21 = (x1+x2)/2;
    float y21 = (y1+y2)/2;
    float x23 = (x2+x3)/2;
    float y23 = (y2+y3)/2;
    float x13 = (x1+x3)/2;
    float y13 = (y1+y3)/2;

    drawtriangle(x1,y1,x2,y2,x3,y3);
    if (counter>0)
    {
        drawfigure(x1, y1, x21, y21, x13, y13, counter-1);
        drawfigure(x21, y21, x2, y2, x23, y23, counter-1);
        drawfigure(x13, y13, x23, y23, x3, y3, counter-1);
    }
    
}

void renderFunction() 
{
    glClearColor(1.0,1.0,1.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    int counter = 4;
    drawfigure(-1.0, -0.5, 1.0, -0.5, 0.0, 1.0, counter);
}


int main(int argc, char **argv) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Repeating Triangle");

    glutDisplayFunc(renderFunction);
    glutMainLoop();
    
    return 0;

}