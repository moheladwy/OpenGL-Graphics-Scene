#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/glut.h>
#include <iostream>
#include <GL/freeglut_std.h>

#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")

void MyInit1();
void Draw_Square();
//int main(int c, char* v[]);

//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow) {
//    return main(__argc, __argv);
//}

void MyInit1() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glColor3f(0.7, 0.0, 0.5);
}

void Draw_Square() {
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_POLYGON);
    glVertex2d(-0.5, 0.5);
    glVertex2d(0.5, 0.5);
    glVertex2d(0.5, -0.5);
    glVertex2f(-0.5, -0.5);
    glEnd();

    glFlush();
}

//int main(int c, char* v[]) {
//    glutInit(&c, v);
//    glutInitWindowPosition(0, 0);
//    glutInitWindowSize(800, 600);
//    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
//    glutCreateWindow("Draw Square");
//    MyInit1();
//    glutDisplayFunc(Draw_Square);
//    glutMainLoop();
//    return 0;
//}

