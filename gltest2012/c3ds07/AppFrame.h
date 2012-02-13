// AppFrame.h: interface for the CAppFrame class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_APPFRAME_H__INCLUDED_)
#define AFX_APPFRAME_H__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Window.h"
#include "3dModel.h"

class CAppFrame : public CWindow
{
public:
	CAppFrame(string Name, int PosX, int PosY, int DimX, int DimY);
	void	Display(void);
	void	Reshape(int DimX, int DimY);
	void	Idle(void);
	void	Init(void);
	void	Keyboard(unsigned char key, int x, int y);
// Application frames
	C3DModel	*ModelloPtr;
private:
	float		mScale;
	float		Degree;
};

#endif // !defined(AFX_APPFRAME_H__INCLUDED_)
