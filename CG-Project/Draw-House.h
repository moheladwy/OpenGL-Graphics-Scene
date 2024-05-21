#pragma once
#include <Windows.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <GL/glut.h>
#include <GL/freeglut_std.h>
#include <math.h>
#include <cstdlib>

#pragma comment(lib,"opengl32.lib")
#pragma comment(lib,"glu32.lib")

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

// Define the window properties.
#define W_WIDTH  800
#define W_HEIGHT 600
#define W_POS_X  0
#define W_POS_Y  0
#define SPEED_RATE  3

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
const GLfloat DoorVertices[4][3] = {
    {-0.1f, -0.25f, 0.01f}, // v1
    { 0.1f, -0.25f, 0.01f}, // v2
    { 0.1f, -0.75f, 0.01f}, // v3
    {-0.1f, -0.75f, 0.01f}, // v4
};

// TODO: To be determined.
const GLfloat WindowsLocations[4][3] = {
    { -0.25f,  0.25f, 0.01f}, // W1
    { -0.25f, -0.05f, 0.01f}, // W2
    {  0.25f,  0.25f, 0.01f}, // W3
    {  0.25f, -0.05f, 0.01f}, // W4
};

void MyInit();
void setColor(int r, int g, int b);
void setClearColor(int r, int g, int b);
void DrawHouse();

// Roof Functions.
void DrawRoof(const GLfloat* v1, const GLfloat* v2, const GLfloat* v3);
void DrawAllRoofFaces();

// Face Functions.
void DrawFace(const GLfloat* v1, const GLfloat* v2, const GLfloat* v3, const GLfloat* v4, int r, int g, int b);
void DrawAllHouseFaces();

// Window Functions.
void DrawWindow(const GLfloat* w);
void DrawLeftWindows();
void DrawRightWindows();
void OpenWindows();
void CloseWindows();

// Door Functions.
void DrawDoor();
void OpenDoor();
void CloseDoor();

// Bicycle Functions.
void MoveBicycleForward();
void MoveBicycleBackward();
void MoveBicycleRight();
void MoveBicycleLeft();

// Keyboard Functions.
void LetterKeys(unsigned char key, int x, int y);
void SpecialKeys(int key, int x, int y);

void Spin();
int main(int c, char* v[]);
