
#include <windows.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#include"game.h"

#define COLUMNS 40
#define ROWS 40
#define FPS 10
int score=0;
extern short sDirection;
bool gameOver=FALSE;

void init()
{

    glClearColor(1.0,1.0,1.0,1.0);
    initGrid(COLUMNS,ROWS);
}


void display_callback()
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawGrid();
	drawSnake();
	drawFood();
	glutSwapBuffers();
	if(gameOver)
    {
        char _score[10];
        itoa(score,_score,10);
        char text[50]="YOUR SCORE IS:";
        strcat(text,_score);
        MessageBox(NULL,text,"GAME OVER!!!",0);
        exit(0);
    }
}

void reshape_callback(int w,int h)
{

    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
}

void timer_callback(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/FPS,timer_callback,0);
}

void keyboard_callback(int key,int,int)
{
switch(key)
{
case GLUT_KEY_UP:
    if(sDirection!=DOWN)
        sDirection=UP;
    break;

case GLUT_KEY_DOWN:
    if(sDirection!=UP)
        sDirection=DOWN;
    break;

case GLUT_KEY_RIGHT:
    if(sDirection!=LEFT)
        sDirection=RIGHT;
    break;

case GLUT_KEY_LEFT:
    if(sDirection!=RIGHT)
        sDirection=LEFT;
    break;
}
}

int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (400,100);
	glutCreateWindow ("SNAKE GAME by Suren Ayer");
	glutDisplayFunc(display_callback);
	glutTimerFunc(0,timer_callback,0);
    glutSpecialFunc(keyboard_callback);
	init();
	glutReshapeFunc(reshape_callback);
	glutMainLoop();

return 0;}
