// Window.h: interface for the CWindow class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(WINDOW_H__INCLUDED_)
#define WINDOW_H__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CWindow
{
public:
	CWindow(string Title, int PosX, int PosY, int DimX, int DimY);
	string	GetTitle() const {return mTitle;}
	int		GetDimX() const {return mDimX;}
	int		GetDimY() const {return mDimY;}
	int		GetPosX() const {return mPosX;}
	int		GetPosY() const {return mPosY;}
	virtual void Init();
	virtual	void Reshape(int DimX, int DimY);
	virtual void Display();
	virtual void Idle();
	virtual void Keyboard(unsigned char key, int x, int y);
private:
	string mTitle;
	int	mPosX, mPosY;
	int mDimX, mDimY;
};


#endif // !defined(WINDOW_H__INCLUDED_)
