// ViewControl.h: interface for the CViewControl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(VIEWCTRL_H__INCLUDED_)
#define VIEWCTRL_H__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CWindow;

class CViewControl
{
public:
	CViewControl(string ApplicationName);
	static	void		Reshape(int Width, int Height);
	static	void		Display();
	static	void		Idle();
	static	void		Keyboard(unsigned char key, int x, int y);
	virtual	bool		AppendWindow(CWindow *Window);
	virtual	bool		Start();
	virtual	bool		RedrawAll();
private:
	int					mCount;							// Number of windows
	const string		mApplicationName;
	vector		<int>	mHandles;
};

#endif // !defined(VIEWCTRL_H__INCLUDED_)
