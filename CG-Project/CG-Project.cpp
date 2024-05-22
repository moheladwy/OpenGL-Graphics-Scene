#pragma once
#include "CG-Project.h"

/*
* ===================
    Global Variables
* ===================
*/
double leftWindowsRotationAngle  = 0.0;
double rightWindowsRotationAngle = 0.0;
double doorRotationAngle         = 0.0;
double bicycleMovingFactor       = 0.0;
double bicycleRotationAngle      = 0.0;
double wheelRotationAngle        = 0.0;
bool   animationActivation       = false;

double rotationAngle = 0;
double rotateX       = 0;
double rotateY       = 0;
double rotateZ       = 0;
double scaleX        = 1;
double scaleY        = 1;
double scaleZ        = 1;

/*
* ====================
    General Functions
* ====================
*/
void setColor(int r, int g, int b)
{
    // Function to convert RGB values to the range 0.0-1.0
    glColor3f(r / 255.0f, g / 255.0f, b / 255.0f);
}

void setClearColor(int r, int g, int b)
{
    // Function to convert RGB values to the range 0.0-1.0
    glClearColor(r / 255.0f, g / 255.0f, b / 255.0f, 1.0f);
}

void MyInit()
{
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

    // Set the Keyboard and Mouse functions
    glutKeyboardFunc(LetterKeys);
    glutSpecialFunc(SpecialKeys);
    glutMouseFunc(Mouse);

    // Set the display function
    glutDisplayFunc(DrawScene);
    glutIdleFunc(BicycleCircularMovement);
}

/*
* ==================
    Scene Functions
* ==================
*/
void DrawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    SceneTransformation();
    scaleX = 1.0;
    scaleY = 1.0;
    scaleZ = 1.0;
    rotationAngle = 0.0;
    rotateX = 0.0;
    rotateY = 0.0;
    rotateZ = 0.0;

    // Draw the house components
    DrawAllRoofFaces();
    DrawAllHouseFaces();
    DrawLeftWindows();
    DrawRightWindows();
    DrawDoor();

    // Draw the street and the bicycle
    DrawStreet();
    DrawBicycle();

    glutSwapBuffers();
}

void SceneTransformation()
{
    glRotatef(rotationAngle, rotateX, rotateY, rotateZ);
    glScaled(scaleX, scaleY, scaleZ);

}

void SceneZoomIn()
{
    glMatrixMode(GL_PROJECTION);
    scaleX = 0.9;
    scaleY = 0.9;
    scaleZ = 0.9;
    rotationAngle = 0.0;
    rotateX = 0.0;
    rotateY = 0.0;
    rotateZ = 0.0;
}

void SceneZoomOut()
{
    glMatrixMode(GL_PROJECTION);
    scaleX = 1.1;
    scaleY = 1.1;
    scaleZ = 1.1;
    rotationAngle = 0.0;
    rotateX = 0.0;
    rotateY = 0.0;
    rotateZ = 0.0;
}

void SceneRotateLeft()
{
    glMatrixMode(GL_MODELVIEW);
    rotationAngle = 2.0;
    rotateX = 0.0;
    rotateY = 1.0;
    rotateZ = 0.0;
}

void SceneRotateRight()
{
    glMatrixMode(GL_MODELVIEW);
    rotationAngle = -2.0;
    rotateX = 0.0;
    rotateY = 1.0;
    rotateZ = 0.0;
}

void SceneRotateUp()
{
    glMatrixMode(GL_MODELVIEW);
    rotationAngle = 2.0;
    rotateX = 1.0;
    rotateY = 0.0;
    rotateZ = 0.0;
}

void SceneRotateDown()
{
    glMatrixMode(GL_MODELVIEW);
    rotationAngle = -2.0;
    rotateX = 1.0;
    rotateY = 0.0;
    rotateZ = 0.0;
}

void ResetScene() {
    glMatrixMode(GL_MODELVIEW);
    scaleX = 1.0;
    scaleY = 1.0;
    scaleZ = 1.0;
    rotationAngle = 0.0;
    rotateX = 0.0;
    rotateY = 0.0;
    rotateZ = 0.0;
}

/*
* ================
    Drawing Roof
* ================
*/
void DrawRoof(const GLfloat *v1, const GLfloat *v2, const GLfloat *v3)
{
    setColor(RED); // Set the drawing color to red
    // Begin drawing the triangle
    glBegin(GL_TRIANGLES);
    // Specify the vertices of the triangle
    glVertex3fv(v1); // First vertex
    glVertex3fv(v2); // Second vertex
    glVertex3fv(v3); // Third vertex
    glEnd();
    // glutSwapBuffers();
}

void DrawAllRoofFaces()
{
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

void DrawFace(const GLfloat *v1, const GLfloat *v2, const GLfloat *v3, const GLfloat *v4, int r, int g, int b)
{
    setColor(r, g, b); // Set the drawing color to blue
    // Begin drawing the polygon
    glBegin(GL_QUADS);
        glVertex3fv(v1); // First vertex
        glVertex3fv(v2); // Second vertex
        glVertex3fv(v3); // Third vertex
        glVertex3fv(v4); // Fourth vertex
    glEnd();
}

void DrawAllHouseFaces()
{
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
void DrawWindow(const GLfloat *w, int r, int g, int b)
{
    setColor(r, g, b); // Set the drawing color to yellow
    // Begin drawing the polygon
    glBegin(GL_QUADS);
        glVertex3f(w[0] - 0.1f, w[1] + 0.1f, w[2]); // First vertex
        glVertex3f(w[0] + 0.1f, w[1] + 0.1f, w[2]); // Second vertex
        glVertex3f(w[0] + 0.1f, w[1] - 0.1f, w[2]); // Third vertex
        glVertex3f(w[0] - 0.1f, w[1] - 0.1f, w[2]); // Fourth vertex
    glEnd();
}

void DrawLeftWindows()
{
    // Draw the back windows.
    DrawWindow(BackWindowsLocations[0], GRAY); // W1
    DrawWindow(BackWindowsLocations[1], GRAY); // W2

    // Draw the front windows.
    glPushMatrix();

    glTranslated(-0.35, 0.0, 0.0);
    glRotated(-1 * leftWindowsRotationAngle, 0, 1, 0);
    glTranslated(0.35, 0.0, 0.0);

    DrawWindow(FrontWindowsLocations[0], YELLO); // W1
    DrawWindow(FrontWindowsLocations[1], YELLO); // W2

    glPopMatrix();
}

void DrawRightWindows()
{
    // Draw the back windows.
    DrawWindow(BackWindowsLocations[2], GRAY); // W3
    DrawWindow(BackWindowsLocations[3], GRAY); // W4

    // Draw the front windows.
    glPushMatrix();

    glTranslated(0.35, 0.0, 0.0);
    glRotated(-1 * rightWindowsRotationAngle, 0, 1, 0);
    glTranslated(-0.35, 0.0, 0.0);

    DrawWindow(FrontWindowsLocations[2], YELLO); // W3
    DrawWindow(FrontWindowsLocations[3], YELLO); // W4

    glPopMatrix();
}

void OpenWindows()
{
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

void CloseWindows()
{
    if (leftWindowsRotationAngle > 0)
    {
        leftWindowsRotationAngle -= SPEED_RATE;
        glutPostRedisplay();
    }
    if (rightWindowsRotationAngle < 0)
    {
        rightWindowsRotationAngle += SPEED_RATE;
        glutPostRedisplay();
    }
}

/*
* ===============
    Drawing Door
* ===============
*/
void DrawDoor()
{
    DrawFace(BackDoorVertices[0], BackDoorVertices[1], BackDoorVertices[2], BackDoorVertices[3], GRAY);

    glPushMatrix();

    glTranslated(-0.1, 0.0, 0.0);
    glRotated(doorRotationAngle, 0, -1, 0);
    glTranslated(0.1, 0.0, 0.0);

    DrawFace(FrontDoorVertices[0], FrontDoorVertices[1], FrontDoorVertices[2], FrontDoorVertices[3], ORANGE);

    glPopMatrix();
}

void OpenDoor()
{
    if (doorRotationAngle < 89.0)
    {
        doorRotationAngle += SPEED_RATE;
        glutPostRedisplay();
    }
}

void CloseDoor()
{
    if (doorRotationAngle > 0)
    {
        doorRotationAngle -= SPEED_RATE;
        glutPostRedisplay();
    }
}

/*
* ====================
    Street Functions
* ====================
*/
void DrawFilledCircle(const GLfloat& x, const GLfloat& y, const GLfloat& z, const GLfloat& radius)
{
    int num_segments = 100;
    GLfloat angle;
    glBegin(GL_TRIANGLE_FAN);
    setColor(GRAY); // Set the color to grey for the street
    glVertex3f(x, y, z);
    for (int i = 0; i <= num_segments; i++)
    {
        angle = i * 2.0f * 3.14159f / num_segments;
        glVertex3f(x + (cos(angle) * radius), y, z + (sin(angle) * radius));
    }
    glEnd();
}

void DrawStreet()
{
    DrawFilledCircle(0.0f, -0.7501f, -0.2f, 2.0f);
}

/*
* ====================
    Bicycle Functions
* ====================
*/
void DrawWheel(const GLfloat& x, const GLfloat& y, const GLfloat& z, const GLfloat& radius)
{
    int num_segments = 100;
    GLfloat angle;
    glBegin(GL_TRIANGLE_FAN);
    setColor(LIGHT_BLACK); 
    glVertex3f(x, y, z);
    for (int i = 0; i <= num_segments; i++)
    {
        angle = i * 2.0f * PI / num_segments;
        glVertex3f(x + (cos(angle) * radius), y + (sin(angle) * radius), z);
    }
    glEnd();
}

void DrawBicycleBody()
{
    // Front face
    DrawFace(BodyVertices[0], BodyVertices[1], BodyVertices[2], BodyVertices[3], RED);
    // Back face
    DrawFace(BodyVertices[4], BodyVertices[5], BodyVertices[6], BodyVertices[7], RED);
    // Left face
    DrawFace(BodyVertices[0], BodyVertices[3], BodyVertices[7], BodyVertices[4], RED);
    // Right face
    DrawFace(BodyVertices[1], BodyVertices[2], BodyVertices[6], BodyVertices[5], RED);
    // Top face
    DrawFace(BodyVertices[3], BodyVertices[2], BodyVertices[6], BodyVertices[7], RED);
    // Bottom face
    DrawFace(BodyVertices[0], BodyVertices[1], BodyVertices[5], BodyVertices[4], RED);
}

void DrawBicycleHandleNeck()
{
    // Front face
    DrawFace(HandleNeck[0], HandleNeck[1], HandleNeck[2], HandleNeck[3], MAGEN);
    // Back face
    DrawFace(HandleNeck[4], HandleNeck[5], HandleNeck[6], HandleNeck[7], MAGEN);
    // Left face
    DrawFace(HandleNeck[0], HandleNeck[3], HandleNeck[7], HandleNeck[4], MAGEN);
    // Right face
    DrawFace(HandleNeck[1], HandleNeck[2], HandleNeck[6], HandleNeck[5], MAGEN);
    // Top face
    DrawFace(HandleNeck[3], HandleNeck[2], HandleNeck[6], HandleNeck[7], MAGEN);
    // Bottom face
    DrawFace(HandleNeck[0], HandleNeck[1], HandleNeck[5], HandleNeck[4], MAGEN);
}

void DrawBicycleHandle()
{   
    // Front face
    DrawFace(Handle[0], Handle[1], Handle[2], Handle[3], LIGHT_BLACK);
    // Back face
    DrawFace(Handle[4], Handle[5], Handle[6], Handle[7], LIGHT_BLACK);
    // Left face
    DrawFace(Handle[0], Handle[3], Handle[7], Handle[4], LIGHT_BLACK);
    // Right face
    DrawFace(Handle[1], Handle[2], Handle[6], Handle[5], LIGHT_BLACK);
    // Top face
    DrawFace(Handle[3], Handle[2], Handle[6], Handle[7], LIGHT_BLACK);
    // Bottom face
    DrawFace(Handle[0], Handle[1], Handle[5], Handle[4], LIGHT_BLACK);
}

void DrawBicycleWheels() {
    // Draw front wheel with proper transformations
    glPushMatrix();
    glTranslated(0.2, -0.65, 0.875); // Translate to the wheel's position
    glRotated(wheelRotationAngle, 0, -1, 0); // Rotate the wheel around its own axis
    DrawWheel(0, 0, 0, 0.1); // Draw the wheel at the origin
    glTranslated(-0.2, 0.65, -0.875); // Translate to the wheel's position
    glPopMatrix();

    // Draw back wheel with proper transformations
    DrawWheel(-0.2, -0.65, 0.875, 0.1); // Draw the wheel.
}

void DrawBicycle()
{
    glPushMatrix();
    glRotated(bicycleRotationAngle, 0, -1, 0); // Rotate the entire bicycle
    glTranslated(bicycleMovingFactor, 0.0, 0.0); // Move the entire bicycle

    // Draw bicycle body parts
    DrawBicycleBody();
    DrawBicycleHandleNeck();
    DrawBicycleHandle();
    DrawBicycleWheels();

    glPopMatrix();
}

void MoveBicycleForward()
{
    bicycleMovingFactor += 0.06;
    wheelRotationAngle = 0;
    glutPostRedisplay();
}

void MoveBicycleBackward()
{
    bicycleMovingFactor -= 0.06;
    wheelRotationAngle = 0;
    glutPostRedisplay();
}

void MoveBicycleRight()
{
    if (wheelRotationAngle < MAX_WHEEL_ROTATION_ANGLE)
    {
        wheelRotationAngle += SPEED_RATE;
        glutPostRedisplay();
    }
}

void MoveBicycleLeft()
{
    if (wheelRotationAngle > -MAX_WHEEL_ROTATION_ANGLE) {
        wheelRotationAngle -=SPEED_RATE;
        glutPostRedisplay();
    }
}

void BicycleCircularMovement() {
    if (animationActivation) {
        bicycleRotationAngle -= 1;
        if (bicycleRotationAngle <= -360.0) {
            bicycleRotationAngle += 360.0;
        }
        wheelRotationAngle = -20;
        glutPostRedisplay();
    }
}

/*
* ===============================
    Keyboard and Mouse Functions
* ===============================
*/
void LetterKeys(unsigned char key, int x, int y)
{
    switch (key)
    {
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
    case 'Z': // Zoom out
        SceneZoomOut();
        break;
    case 'z': // Zoom in
        SceneZoomIn();
        break;
    case 'R': // Reset the scene
        ResetScene();
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

void SpecialKeys(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        SceneRotateUp();
        break;
    case GLUT_KEY_DOWN:
        SceneRotateDown();
        break;
    case GLUT_KEY_LEFT:
        SceneRotateLeft();
        break;
    case GLUT_KEY_RIGHT:
        SceneRotateRight();
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

void Mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            animationActivation = true; // Start animation when left button is pressed
        }
    }
    if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN) {
            animationActivation = false; // Stop animation when right button is pressed
        }
    }
    glutPostRedisplay();
}

/*
* ================
    Main Function
* ================
*/
int main(int c, char *v[])
{
    glutInit(&c, v);
    glutInitWindowPosition(W_POS_X, W_POS_Y); // Set the window position
    glutInitWindowSize(W_WIDTH, W_HEIGHT);    // Set the window size
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Draw House");
    MyInit();
    glutMainLoop();
    return 0;
}
