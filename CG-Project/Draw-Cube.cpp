//#include <Windows.h>
//#include <gl/GL.h>
//#include <gl/GLU.h>
//#include <GL/glut.h>
//#include <iostream>
//#include <GL/freeglut_std.h>
//
//#pragma comment(lib,"opengl32.lib")
//#pragma comment(lib,"glu32.lib")
//
//GLfloat T = 0.0;
//
//void MyInit();
//void DrawCube();
//void Face(GLfloat* v1, GLfloat* v2, GLfloat* v3, GLfloat* v4);
//void Cube(GLfloat* v1, GLfloat* v2, GLfloat* v3, GLfloat* v4, GLfloat* v5, GLfloat* v6, GLfloat* v7, GLfloat* v8);
//void Spin();
//int main(int c, char* v[]);
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow) {
//    return main(__argc, __argv);
//}
//
//void MyInit() {
//    glClearColor(0.0, 0.0, 0.0, 1.0);
//    glColor3f(0.0, 0.0, 0.25);
//    glEnable(GL_DEPTH_TEST);
//}
//
//void Face(GLfloat* a, GLfloat* b, GLfloat* c, GLfloat* d) {
//    glBegin(GL_POLYGON);
//        glVertex3fv(a);
//        glVertex3fv(b);
//        glVertex3fv(c);
//        glVertex3fv(d);
//    glEnd();
//}
//
//void Cube(GLfloat* v0, GLfloat* v1, GLfloat* v2, GLfloat* v3, GLfloat* v4, GLfloat* v5, GLfloat* v6, GLfloat* v7) {
//    glColor3f(0.0, 0.0, 0.5);
//    Face(v0, v1, v2, v3); // Front
//
//    glColor3f(0.0, 0.5, 0.0);
//    Face(v4, v5, v6, v7); // Back
//
//    glColor3f(0.5, 0.0, 0.0);
//    Face(v0, v3, v7, v4); // Left
//
//    glColor3f(0.0, 0.5, 0.5);
//    Face(v1, v2, v6, v5); // Right
//
//    glColor3f(0.5, 0.5, 0.0);
//    Face(v0, v1, v5, v4); // Top
//
//    glColor3f(0.5, 0.5, 0.5);
//    Face(v3, v2, v6, v7); // Bottom
//}
//
//void DrawCube() {
//    GLfloat V[8][3] = {
//                            { -0.5,  0.5,  0.5 },
//                            {  0.5,  0.5,  0.5 },
//                            {  0.5, -0.5,  0.5 },
//                            { -0.5, -0.5,  0.5 },
//                            { -0.5,  0.5, -0.5 },
//                            {  0.5,  0.5, -0.5 },
//                            {  0.5, -0.5, -0.5 },
//                            { -0.5, -0.5, -0.5 }
//                      };
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();
//    glRotatef(T, 1.0, 1.0, 1.0);
//    Cube(V[0], V[1], V[2], V[3], V[4], V[5], V[6], V[7]);
//    glutSwapBuffers();
//}
//
//void Spin() {
//    T += 0.05;
//    if (T > 360.0) T = 0.0;
//    glutPostRedisplay();
//}
//
//int main(int c, char* v[]) {
//    glutInit(&c, v);
//    glutInitWindowPosition(250, 0);
//    glutInitWindowSize(800, 600);
//    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
//    glutCreateWindow("Draw Cupe That Spins");
//    MyInit();
//    glutDisplayFunc(DrawCube);
//    glutIdleFunc(Spin);
//    glutMainLoop();
//    return 0;
//}
//
