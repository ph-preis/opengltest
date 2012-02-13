// 3DCamera.h: interface for the C3DCamera class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_3DCAMERA_H__INCLUDED_)
#define AFX_3DCAMERA_H__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class C3DCamera
{
public:
	C3DCamera();
	C3DCamera(VECTOR Position, VECTOR Target, float Bank, float Lens) : position(Position),
																		target(Target),
																		bank(Bank),
																		lens(Lens) {}
	VECTOR	position;
	VECTOR	target;
	float	bank, lens;
};

#endif // !defined(AFX_3DCAMERA_H__INCLUDED_)
