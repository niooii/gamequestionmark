#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#define GLUT_DISABLE_ATEXIT_HACK
#include <GL/glut.h>
#include <math.h>
#define PI 3.1415926535897932384

const int WIDTH = 512;
const int HEIGHT = 512;

float playerX, playerY; //player position
float playerDeltaX, playerDeltaY, playerAngle;

void drawPlayer(){
    glColor3f(1,1,0);
    glPointSize(8);
    glBegin(GL_POINTS);
    glVertex2i(playerX, playerY);
    glEnd();

    glLineWidth(3);
    glBegin(GL_LINES);
    glVertex2i(playerX, playerY);
    glVertex2i(playerX + playerDeltaX * 5, playerY + playerDeltaY * 5);
    glEnd();
}

const int mapX = 8, mapY = 8, mapSize = 64;
int map[][8]=
        {
        1, 1, 1, 1, 1, 1, 1, 1,
        1, 0, 1, 0, 0, 0, 0, 1,
        1, 0, 1, 0, 0, 0, 0, 1,
        1, 0, 1, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 0, 0, 0, 0, 1, 0, 1,
        1, 0, 0, 0, 0, 0, 0, 1,
        1, 1, 1, 1, 1, 1, 1, 1
        };

void drawMap2D()
{
    for(int x = 0; x < mapX; x++){
        for(int y = 0; y < mapY; y++){ // if int = 1, draw white box else draw black
            if(map[y][x] == 1) { glColor3f(1,1,1); } else { glColor3f(0, 0, 0);  }
            glBegin(GL_QUADS);
            glVertex2i(x * mapSize + 1, y * mapSize + 1);
            glVertex2i(x * mapSize + 1, y * mapSize + mapSize - 1);
            glVertex2i(x * mapSize + mapSize - 1, y * mapSize + mapSize - 1);
            glVertex2i(x * mapSize + mapSize - 1, y * mapSize + 1);
            glEnd();
        }
    }
}


void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawMap2D();
    drawPlayer();
    glutSwapBuffers();
}
void buttons(unsigned char key, int x, int y){
    if(key=='a')
    {
        playerAngle-=0.1;
        if(playerAngle < 0)
        {
            playerAngle += 2*PI;
        }
        playerDeltaX = cos(playerAngle) * 5;
        playerDeltaY = sin(playerAngle) * 5;
    }
    if(key=='d')
    {
        playerAngle+=0.1;
        if(playerAngle > 2*PI)
        {
            playerAngle += 2*PI;
        }
        playerDeltaX = cos(playerAngle) * 5;
        playerDeltaY = sin(playerAngle) * 5;
    }
    if(key=='w')
    {
        playerX += playerDeltaX;
        playerY += playerDeltaY;
    }
    if(key=='s')
    {
        playerX -= playerDeltaX;
        playerY -= playerDeltaY;
    }
    if(playerX < 0)
        playerX = glutGet(GLUT_WINDOW_WIDTH);
    if(playerX > glutGet(GLUT_WINDOW_WIDTH))
        playerX = 0;
    if(playerY < 0)
        playerY = glutGet(GLUT_WINDOW_HEIGHT);
    if(playerY > glutGet(GLUT_WINDOW_HEIGHT))
        playerY = 0;

    glutPostRedisplay();
}

void init(){
    glClearColor(0.3, 0.3, 0.3, 0);
    gluOrtho2D(0, 512, 512, 0);
    playerX=300; playerY=300;
    playerDeltaX = cos(playerAngle) * 5;
    playerDeltaY = sin(playerAngle) * 5;
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("AWHUGJAWFYUWA");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(buttons);
    glutMainLoop();
}
