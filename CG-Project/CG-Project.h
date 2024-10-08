#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/glut.h>
#include <GL/freeglut_std.h>
#include <math.h>
#include <cstdlib>

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")

// Define the RGB values for the colors.
#define MAIN_CLEAR_COLOR 0   , 100 , 0
#define BLACK            0   , 0   , 0
#define RED              255 , 0   , 0
#define GREEN            0   , 255 , 0
#define BLUE             0   , 0   , 255
#define YELLO            255 , 255 , 0
#define CYAN             0   , 255 , 255
#define MAGEN            255 , 0   , 255
#define WHITE            255 , 255 , 255
#define ORANGE           255 , 165 , 0
#define GRAY             80  , 80  , 80
#define LIGHT_BLACK      30  , 30  , 30

// Define the window properties.
#define W_WIDTH  800
#define W_HEIGHT 600
#define W_POS_X  0
#define W_POS_Y  0
#define SPEED_RATE  3

// Define the Scene properties.
#define SPEED_RATE               3
#define PI                       3.14159f
#define MAX_WHEEL_ROTATION_ANGLE 45
#define X_AXIS                   0
#define Y_AXIS                   1
#define Z_AXIS                   2

// Define the Roof vertices.
const GLfloat RoofVertices[6][3] = {
    {-0.50f, 0.50f, 0.0f}, // v1
    { 0.50f, 0.50f, 0.0f}, // v2
    { 0.00f, 0.75f, 0.0f}, // v3
    {-0.50f, 0.50f,-0.5f}, // v4
    { 0.50f, 0.50f,-0.5f}, // v5
    { 0.00f, 0.75f,-0.5f}  // v6
};

// Define the house vertices.
const GLfloat HouseVertices[8][3] = {
    {-0.50f, 0.50f, 0.0f}, // v1
    { 0.50f, 0.50f, 0.0f}, // v2
    { 0.50f,-0.75f, 0.0f}, // v3
    {-0.50f,-0.75f, 0.0f}, // v4
    {-0.50f, 0.50f,-0.5f}, // v5
    { 0.50f, 0.50f,-0.5f}, // v6
    { 0.50f,-0.75f,-0.5f}, // v7
    {-0.50f,-0.75f,-0.5f}, // v8
};

// Define the Door vertices.
const GLfloat BackDoorVertices[4][3] = {
    {-0.1f, -0.25f, 0.009f}, // v1
    { 0.1f, -0.25f, 0.009f}, // v2
    { 0.1f, -0.75f, 0.009f}, // v3
    {-0.1f, -0.75f, 0.009f}, // v4
};

const GLfloat FrontDoorVertices[4][3] = {
    {-0.1f, -0.25f, 0.01f}, // v1
    { 0.1f, -0.25f, 0.01f}, // v2
    { 0.1f, -0.75f, 0.01f}, // v3
    {-0.1f, -0.75f, 0.01f}, // v4
};

// Define the Windows locations.
const GLfloat BackWindowsLocations[4][3] = {
    {-0.25f, 0.25f, 0.009f}, // W1
    {-0.25f,-0.05f, 0.009f}, // W2
    { 0.25f, 0.25f, 0.009f}, // W3
    { 0.25f,-0.05f, 0.009f}, // W4
};

const GLfloat FrontWindowsLocations[4][3] = {
    {-0.25f, 0.25f, 0.01f}, // W1
    {-0.25f,-0.05f, 0.01f}, // W2
    { 0.25f, 0.25f, 0.01f}, // W3
    { 0.25f,-0.05f, 0.01f}, // W4
};

// Define the Bicycle vertices.
const GLfloat BodyVertices[8][3] = {
    {-0.2f, -0.50f, 0.95f}, // v1
    { 0.2f, -0.50f, 0.95f}, // v2
    { 0.2f, -0.55f, 0.95f}, // v3
    {-0.2f, -0.55f, 0.95f}, // v4
    {-0.2f, -0.50f, 0.80f}, // v5
    { 0.2f, -0.50f, 0.80f}, // v6
    { 0.2f, -0.55f, 0.80f}, // v7
    {-0.2f, -0.55f, 0.80f}, // v8
};

// Define the Bicycle Handle Neck vertices.
const GLfloat HandleNeck[8][3] = {
    {0.15f, -0.4f, 0.85f}, // v1
    {0.20f, -0.4f, 0.85f}, // v2
    {0.20f, -0.5f, 0.85f}, // v3
    {0.15f, -0.5f, 0.85f}, // v4
    {0.15f, -0.4f, 0.90f}, // v5
    {0.20f, -0.4f, 0.90f}, // v6
    {0.20f, -0.5f, 0.90f}, // v7
    {0.15f, -0.5f, 0.90f}, // v8
};

// Define the Bicycle Handle vertices.
const GLfloat Handle[8][3] = {
    {0.15f, -0.3f, 0.95f}, // v1
    {0.20f, -0.3f, 0.95f}, // v2
    {0.20f, -0.4f, 0.95f}, // v3
    {0.15f, -0.4f, 0.95f}, // v4
    {0.15f, -0.3f, 0.80f}, // v5
    {0.20f, -0.3f, 0.80f}, // v6
    {0.20f, -0.4f, 0.80f}, // v7
    {0.15f, -0.4f, 0.80f}, // v8
};

// General Functions.
void MyInit();
void setColor(int r, int g, int b);
void setClearColor(int r, int g, int b);

// Scene Functions.
void SceneTransformation();
void SceneZoomIn();
void SceneZoomOut();
void DrawScene();
void SceneRotateLeft();
void SceneRotateRight();
void SceneRotateUp();
void SceneRotateDown();
void ResetScene();

// Roof Functions.
void DrawRoof(const GLfloat *v1, const GLfloat *v2, const GLfloat *v3);
void DrawAllRoofFaces();

// Face Functions.
void DrawFace(const GLfloat *v1, const GLfloat *v2, const GLfloat *v3, const GLfloat *v4, int r, int g, int b);
void DrawAllHouseFaces();

// Window Functions.
void DrawWindow(const GLfloat* w, int r, int g, int b);
void DrawLeftWindows();
void DrawRightWindows();
void OpenWindows();
void CloseWindows();

// Door Functions.
void DrawDoor();
void OpenDoor();
void CloseDoor();

// Street Functions.
void DrawStreet();
void DrawFilledCircle(const GLfloat& x, const GLfloat& y, const GLfloat& z, const GLfloat& radius);

// Bicycle Functions.
void DrawBicycle();
void DrawWheel(const GLfloat& x, const GLfloat& y, const GLfloat& z, const GLfloat& radius);
void DrawBicycleBody();
void DrawBicycleHandleNeck();
void DrawBicycleHandle();
void DrawBicycleWheels();
void MoveBicycleForward();
void MoveBicycleBackward();
void MoveBicycleRight();
void MoveBicycleLeft();
void BicycleCircularMovement();

// Keyboard Functions.
void LetterKeys(unsigned char key, int x, int y);
void SpecialKeys(int key, int x, int y);
void Mouse(int button, int state, int x, int y);

// Main Functions.
int main(int c, char *v[]);
