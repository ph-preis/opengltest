// ViewControl.cpp: implementation of the CViewControl class.
//
//////////////////////////////////////////////////////////////////////

#include <vector>
#include <string>
using namespace std;

#include <GL/glut.h>

#include "Window.h"
#include "ViewControl.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CWindow *gViewPorts[1];

CViewControl::CViewControl(string ApplicationName) : mCount(0), 
													 mApplicationName(ApplicationName)
{
   char *Argv[1];
   Argv[0] = (char *) mApplicationName.c_str();
   int Argc = 1;

   // Initialize GLUT

   glutInit(&Argc, Argv);
}

void CViewControl::Reshape(int Width, int Height)
{
	int hWnd = glutGetWindow();
	gViewPorts[hWnd]->Reshape(Width, Height);
}

void CViewControl::Display()
{
	int hWnd = glutGetWindow();
	gViewPorts[hWnd]->Display();
}

void CViewControl::Idle()
{
	int hWnd = glutGetWindow();
	gViewPorts[hWnd]->Idle();
}

void CViewControl::Keyboard(unsigned char key, int x, int y)
{
	int hWnd = glutGetWindow();
	gViewPorts[hWnd]->Keyboard(key, x, y);
}

bool CViewControl::AppendWindow(CWindow *Window)
{
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowPosition(Window->GetPosX(), Window->GetPosY());
	int hWnd = glutCreateWindow(Window->GetTitle().c_str());
	gViewPorts[hWnd] = Window;
	glutSetWindow(hWnd);
	Window->Init();
	glutDisplayFunc(Display);
	glutReshapeFunc(Reshape);
	glutIdleFunc(Idle);
	glutKeyboardFunc(Keyboard);
	glutReshapeWindow(Window->GetDimX(), Window->GetDimY());
	mCount++;
	mHandles.push_back(hWnd);
	return true;
}

bool CViewControl::Start()
{
	glutMainLoop();
	return true;
}

bool CViewControl::RedrawAll()
{
	int nHandles = mHandles.size();
	if (nHandles == 0)
		return false;

	for (int i = 0; i < nHandles; i++)
	{
		int hWnd = mHandles[i];
		glutSetWindow(hWnd);
		glutReshapeWindow(gViewPorts[i]->GetDimX(), gViewPorts[i]->GetDimY());
	}
	return true;
}
