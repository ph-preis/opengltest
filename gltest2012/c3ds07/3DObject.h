// 3DObject.h: interface for the C3DObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_3DOBJECT_H__INCLUDED_)
#define AFX_3DOBJECT_H__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include "VECTOR.h"
#include "MATRIX.h"
#include "3DFace.h"

class C3DObject
{
public:
	C3DObject();
	~C3DObject();
	void	UseTrasform();
	vector	<VECTOR> vertices;
	vector	<VECTOR> texturePoints;
	vector	<C3DFace> faces;
	MATRIX	transform;
	float	translate[3];
};

#endif // !defined(AFX_3DOBJECT_H__INCLUDED_)
