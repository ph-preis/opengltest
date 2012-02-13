// Window.cpp: implementation of the CWindow class.
//
//////////////////////////////////////////////////////////////////////

#include <string>
using namespace std;

#include <GL/glut.h>

#include "Window.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWindow::CWindow(string Title, int PosX, int PosY, int DimX, int DimY) : 
				 mTitle(Title), mPosX(PosX), mPosY(PosY), mDimX(DimX), mDimY(DimY)
{
}

void CWindow::Init()
{
	glShadeModel(GL_SMOOTH);     
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);  
	glClearDepth(1.0f);         
	glEnable(GL_DEPTH_TEST);    
	glDepthFunc(GL_LEQUAL);      
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void CWindow::Reshape(int DimX, int DimY)
{
	if (DimY==0)        
	{
		DimY=1;        
	}
	
	glViewport(0, 0, DimX, DimY);   
	glMatrixMode(GL_PROJECTION);   
	glLoadIdentity();      
	
	
	gluPerspective(45.0f,(GLfloat)DimX/(GLfloat)DimY,0.1f,100.0f);
	
	glMatrixMode(GL_MODELVIEW);    
	glLoadIdentity();     
}

void CWindow::Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	glLoadIdentity();        
	glTranslatef(-1.5f,0.0f,-6.0f);     
	glFlush();
}

void CWindow::Idle()
{
	Display();
}

void CWindow::Keyboard(unsigned char key, int x, int y)
{
}
