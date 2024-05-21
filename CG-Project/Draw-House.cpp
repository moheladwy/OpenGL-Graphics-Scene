#pragma once
#include "Draw-House.h"

/*
* ===================
    Global Variables
* ===================
*/
double leftWindowsRotationAngle  = 0.0;
double rightWindowsRotationAngle = 0.0;
double doorRotationAngle         = 0.0;

/*
* ====================
    General Functions
* ====================
*/
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
    //glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

/*
* ================
    Drawing Roof
* ================
*/
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
             HouseVertices[4], BLACK);
    // 4- Draw the Right Face of the House
    DrawFace(HouseVertices[1], HouseVertices[2], HouseVertices[6], 
             HouseVertices[5], BLACK);
    // 5- Draw the Bottom Face of the House
    DrawFace(HouseVertices[3], HouseVertices[2], HouseVertices[6], 
             HouseVertices[7], RED);
}

/*
* ==================
    Drawing Windows
* ==================
*/
void DrawWindow(const GLfloat* w) {
    setColor(YELLO); // Set the drawing color to yellow
    // Begin drawing the polygon
    glBegin(GL_QUADS);
        glVertex3f(w[0] - 0.1f, w[1] + 0.1f, w[2]); // First vertex
        glVertex3f(w[0] + 0.1f, w[1] + 0.1f, w[2]); // Second vertex
        glVertex3f(w[0] + 0.1f, w[1] - 0.1f, w[2]); // Third vertex
        glVertex3f(w[0] - 0.1f, w[1] - 0.1f, w[2]); // Fourth vertex
    glEnd();
}

void DrawLeftWindows() {
    glPushMatrix();

    glTranslated(-0.35, 0.0, 0.0);
    glRotated(-1 * leftWindowsRotationAngle, 0, 1, 0);
    glTranslated( 0.35, 0.0, 0.0);

    DrawWindow(WindowsLocations[0]);  // W1
    DrawWindow(WindowsLocations[1]);  // W2
    
    glPopMatrix();
}

void DrawRightWindows() {
    glPushMatrix();
    
    glTranslated( 0.35, 0.0, 0.0);
    glRotated(-1 * rightWindowsRotationAngle, 0, 1, 0);
    glTranslated(-0.35, 0.0, 0.0);

    DrawWindow(WindowsLocations[2]);  // W3
    DrawWindow(WindowsLocations[3]);  // W4
    
    glPopMatrix();
}

void OpenWindows() {
    if (leftWindowsRotationAngle < 89.0)
    {
        leftWindowsRotationAngle += SPEED_RATE;
        glutPostRedisplay();
    }
    if (rightWindowsRotationAngle > -89.0)
    {
        rightWindowsRotationAngle -= SPEED_RATE;
        glutPostRedisplay();
    }
}

void CloseWindows() {
    if (leftWindowsRotationAngle > 0) {
        leftWindowsRotationAngle -= SPEED_RATE;
        glutPostRedisplay();
    }
    if (rightWindowsRotationAngle < 0) {
        rightWindowsRotationAngle += SPEED_RATE;
        glutPostRedisplay();
    }
}

/*
* ===============
    Drawing Door
* ===============
*/
void DrawDoor() {
    glPushMatrix();

    glTranslated(-0.1, 0.0, 0.0);
    glRotated(doorRotationAngle, 0, -1, 0);
    glTranslated(0.1, 0.0, 0.0);

    DrawFace(DoorVertices[0], DoorVertices[1], DoorVertices[2], DoorVertices[3], ORANGE);
    
    glPopMatrix();
}

void OpenDoor() {
    if (doorRotationAngle < 89.0) {
        doorRotationAngle += SPEED_RATE;
        glutPostRedisplay();
    }
}

void CloseDoor() {
    if (doorRotationAngle > 0) {
        doorRotationAngle -= SPEED_RATE;
        glutPostRedisplay();
    }
}

void DrawHouse() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glLoadIdentity();
    //glRotated(-30, 1, 0, 0);
    //glRotated(20, 0, 1, 0);

    DrawAllRoofFaces();
    DrawAllHouseFaces();
    DrawLeftWindows();
    DrawRightWindows();
    DrawDoor();
    
    glutSwapBuffers();
}

/*
* ====================
    Bicycle Functions
* ====================
*/
void MoveBicycleForward() {

}

void MoveBicycleBackward() {

}

void MoveBicycleRight() {

}

void MoveBicycleLeft() {

}

/*
* =====================
    Keyboard Functions
* =====================
*/
void LetterKeys(unsigned char key, int x, int y) {
    switch (key) {
        case 27:
            exit(0);
            break;
        case 'o': // Open the door
            OpenDoor();
            break;
        case 'c': // Close the door
            CloseDoor();
            break;
        case 'O': // Open the windows
            OpenWindows();
            break;
        case 'C': // Close the windows
            CloseWindows();
            break;
        case 'f': // Go forward
            MoveBicycleForward();
            break;
        case 'b': // Go backward
            MoveBicycleBackward();
            break;
        case 'r': // Go right
            MoveBicycleRight();
            break;
        case 'l': // Go left
            MoveBicycleLeft();
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

void SpecialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            glMatrixMode(GL_MODELVIEW);
            glRotatef(2.0, 1.0, 0.0, 0.0);
            break;
        case GLUT_KEY_DOWN:
            glMatrixMode(GL_MODELVIEW);
            glRotatef(-2.0, 1.0, 0.0, 0.0);
            break;
        case GLUT_KEY_LEFT:
            glMatrixMode(GL_MODELVIEW);
            glRotatef(2.0, 0.0, 1.0, 0.0);
            break;
        case GLUT_KEY_RIGHT:
            glMatrixMode(GL_MODELVIEW);
            glRotatef(-2.0, 0.0, 1.0, 0.0);
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

void Spin() {
    glutPostRedisplay();
}

/*
* ================
    Main Function
* ================
*/
int main(int c, char* v[]) {
    glutInit(&c, v);
    glutInitWindowPosition(W_POS_X, W_POS_Y); // Set the window position
    glutInitWindowSize(W_WIDTH, W_HEIGHT); // Set the window size
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Draw House");
    MyInit();
    glutKeyboardFunc(LetterKeys);
    glutSpecialFunc(SpecialKeys);
    glutDisplayFunc(DrawHouse);
    glutIdleFunc(Spin);
    glutMainLoop();
    return 0;
}
