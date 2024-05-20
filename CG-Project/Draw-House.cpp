#pragma once
#include "Draw-House.h"

void setColor(int r, int g, int b) {
    // Function to convert RGB values to the range 0.0-1.0
    glColor3f(r / 255.0f, g / 255.0f, b / 255.0f);
}

void setClearColor(int r, int g, int b) {
    // Function to convert RGB values to the range 0.0-1.0
    glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, 1.0f);
}

void MyInit() {
    setClearColor(MAIN_CLEAR_COLOR); // Set the clear color to black
    // Set the viewport to cover the entire window
    glViewport(W_POS_X, W_POS_Y, W_WIDTH, W_HEIGHT);
    // Set the projection matrix to the identity matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    // Set the projection matrix to orthographic projection
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

void DrawRoof(const GLfloat* v1, const GLfloat* v2, const GLfloat* v3) {
    setColor(RED); // Set the drawing color to red
    // Begin drawing the triangle
    glBegin(GL_TRIANGLES);
        // Specify the vertices of the triangle
        glVertex3fv(v1); // First vertex
        glVertex3fv(v2); // Second vertex
        glVertex3fv(v3); // Third vertex
    glEnd();
    //glutSwapBuffers();
}

void DrawAllRoofFaces() {
    // 1- Draw the Front Face of the Roof
    DrawRoof(RoofVertices[0], RoofVertices[1], RoofVertices[2]);
    // 2- Draw the Back Face of the Roof
    DrawRoof(RoofVertices[3], RoofVertices[4], RoofVertices[5]);
    // 3- Draw the Left Face of the Roof
    DrawFace(RoofVertices[1], RoofVertices[2], RoofVertices[5], 
             RoofVertices[4], YELLO);
    // 4- Draw the Right Face of the Roof
    DrawFace(RoofVertices[0], RoofVertices[2], RoofVertices[5], 
             RoofVertices[3], YELLO);
}

void DrawFace(const GLfloat* v1, const GLfloat* v2, const GLfloat* v3, const GLfloat* v4, int r, int g, int b) {
    setColor(r, g, b); // Set the drawing color to blue
    // Begin drawing the polygon
    glBegin(GL_QUADS);
        glVertex3fv(v1); // First vertex
        glVertex3fv(v2); // Second vertex
        glVertex3fv(v3); // Third vertex
        glVertex3fv(v4); // Fourth vertex
    glEnd();
}

void DrawAllHouseFaces() {
    // 1- Draw the Front Face of the House
    DrawFace(HouseVertices[0], HouseVertices[1], HouseVertices[2], 
             HouseVertices[3], BLUE);
    // 2- Draw the Back Face of the House
    DrawFace(HouseVertices[4], HouseVertices[5], HouseVertices[6], 
             HouseVertices[7], BLUE);
    // 3- Draw the Left Face of the House
    DrawFace(HouseVertices[0], HouseVertices[3], HouseVertices[7], 
             HouseVertices[4], GREEN);
    // 4- Draw the Right Face of the House
    DrawFace(HouseVertices[1], HouseVertices[2], HouseVertices[6], 
             HouseVertices[5], GREEN);
    // 5- Draw the Bottom Face of the House
    DrawFace(HouseVertices[3], HouseVertices[2], HouseVertices[6], 
             HouseVertices[7], RED);
}

void DrawWindow(const GLfloat &x, const GLfloat &y, const GLfloat &z) {
    setColor(YELLO); // Set the drawing color to yellow
    // Begin drawing the polygon
    glBegin(GL_QUADS);
        glVertex3f(x - 0.1f, y + 0.1f, z); // First vertex
        glVertex3f(x + 0.1f, y + 0.1f, z); // Second vertex
        glVertex3f(x + 0.1f, y - 0.1f, z); // Third vertex
        glVertex3f(x - 0.1f, y - 0.1f, z); // Fourth vertex
    glEnd();
}

void DrawAllWindows() {
    DrawWindow(-0.25f, 0.25f, 0.01f);
    DrawWindow( 0.25f, 0.25f, 0.01f);
    DrawWindow(-0.25f,-0.05f, 0.01f);
    DrawWindow( 0.25f,-0.05f, 0.01f);
}

void DrawDoor(const GLfloat* v1, const GLfloat* v2, const GLfloat* v3, const GLfloat* v4) {
    setColor(GREEN); // Set the drawing color to green
    // Begin drawing the polygon
    glBegin(GL_QUADS);
        glVertex3fv(v1); // First vertex
        glVertex3fv(v2); // Second vertex
        glVertex3fv(v3); // Third vertex
        glVertex3fv(v4); // Fourth vertex
    glEnd();
}

void DrawCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius, GLint numberOfSides) {
    GLint numberOfVertices = numberOfSides + 2; // Number of vertices for the circle
    GLfloat doublePi = 2.0f * 3.14159265358979323846f; // 2 * PI

    // Vertices array for the circle
    GLfloat* circleVerticesX;
    GLfloat* circleVerticesY;
    GLfloat* circleVerticesZ;

    circleVerticesX = new GLfloat[numberOfVertices];
    circleVerticesY = new GLfloat[numberOfVertices];
    circleVerticesZ = new GLfloat[numberOfVertices];

    // Center vertex for the triangle fan
    circleVerticesX[0] = x;
    circleVerticesY[0] = y;
    circleVerticesZ[0] = z;

    for (int i = 1; i < numberOfVertices; i++) {
        circleVerticesX[i] = x + (radius * cos(i * doublePi / numberOfSides));
        circleVerticesY[i] = y + (radius * sin(i * doublePi / numberOfSides));
        circleVerticesZ[i] = z;
    }

    // Draw the circle using triangle fan
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < numberOfVertices; i++) {
        glVertex3f(circleVerticesX[i], circleVerticesY[i], circleVerticesZ[i]);
    }
    glEnd();

    delete[] circleVerticesX;
    delete[] circleVerticesY;
    delete[] circleVerticesZ;
}

void DrawAllCircles() {
    setColor(WHITE); // Set the drawing color to white
    DrawCircle(-0.25f, -0.5f, 0.01f, 0.05f, 100);
}

void DrawHouse() {
    // 1.0- Draw the Roof.
    // 1.1- Draw the Front Face of the House.
    // 1.2- Draw the Windows.
    // 1.3- Draw the Door.
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glRotated(0.1, 1, 1, 0);
    DrawAllRoofFaces();
    DrawAllHouseFaces();
    DrawAllWindows();
    DrawDoor(DoorVertices[0], DoorVertices[1], DoorVertices[2], DoorVertices[3]);
    DrawAllCircles();
    glutSwapBuffers();
}

void Spin() {
    glutPostRedisplay();
}

int main(int c, char* v[]) {
    glutInit(&c, v);
    glutInitWindowPosition(W_POS_X, W_POS_Y); // Set the window position
    glutInitWindowSize(W_WIDTH, W_HEIGHT); // Set the window size
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Draw House");
    MyInit();
    glutDisplayFunc(DrawHouse);
    //glutIdleFunc(Spin);
    glutMainLoop();
    return 0;
}
