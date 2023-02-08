#include <iostream>
#include <fstream>
#include <GL/glut.h>

using namespace std;

float r, g, b, a;

void readFile() 
{
    ifstream file("input.txt");
    if (file.is_open()) 
    {
        file >> r >> g >> b >> a;
        file.close();
    } 

}

void display() {
    glClearColor(r, g, b, a);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char** argv) {
    readFile();
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Background Color");
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
