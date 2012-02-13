// MATRIX.cpp: implementation of the MATRIX class.
//
//////////////////////////////////////////////////////////////////////

#include "VECTOR.H"
#include "MATRIX.h"

// This class MATRIX comes from an article about rigid body
// animation published on www.gamasutra.com so it may
// follow its own license. Please check gamasutra at
// http://www.gamasutra.com/features/19990702/data_structures_01.htm
// or just write your own to replace it.

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MATRIX::MATRIX()
{
	//identity matrix
	C[0].x = 1;
	C[1].y = 1;
	C[2].z = 1;
}

MATRIX::MATRIX( const VECTOR& c0, const VECTOR& c1, const VECTOR& c2 )
{
	C[0] = c0;
	C[1] = c1;
	C[2] = c2;
}

VECTOR& MATRIX::operator [] ( long i )
{
	return C[i];
}

//compare
const bool MATRIX::operator == ( const MATRIX& m ) const
{
	return C[0]==m.C[0] && C[1]==m.C[1] && C[2]==m.C[2];
}

const bool MATRIX::operator != ( const MATRIX& m ) const
{
	return !(m == *this);
}

//assign
const MATRIX& MATRIX::operator = ( const MATRIX& m )
{
	C[0] = m.C[0];
	C[1] = m.C[1];
	C[2] = m.C[2];
	return *this;
}

//increment
const MATRIX& MATRIX::operator +=( const MATRIX& m )
{
	C[0] += m.C[0];
	C[1] += m.C[1];
	C[2] += m.C[2];
	return *this;
}

//decrement
const MATRIX& MATRIX::operator -=( const MATRIX& m ) 
{
	C[0] -= m.C[0];
	C[1] -= m.C[1];
	C[2] -= m.C[2];
	return *this;
}

//self-multiply by a scalar
const MATRIX& MATRIX::operator *= ( const SCALAR& s )
{
	C[0] *= s;
	C[1] *= s;
	C[2] *= s;
	return *this;
}

//self-multiply by a matrix
const MATRIX& MATRIX::operator *= ( const MATRIX& m )
{
	//NOTE: don't change the columns
	//in the middle of the operation
	MATRIX temp = (*this);
	C[0] = temp * m.C[0];
	C[1] = temp * m.C[1];
	C[2] = temp * m.C[2];
	return *this;
}

//add
const MATRIX MATRIX::operator + ( const MATRIX& m ) const
{
	return MATRIX( C[0] + m.C[0], C[1] + m.C[1], C[2] + m.C[2] );
}

//subtract
const MATRIX MATRIX::operator - ( const MATRIX& m ) const
{
	return MATRIX( C[0] - m.C[0], C[1] - m.C[1], C[2] - m.C[2] );
}

//post-multiply by a scalar
const MATRIX MATRIX::operator * ( const SCALAR& s ) const
{
	return MATRIX( C[0]*s, C[1]*s, C[2]*s );
}

//post-multiply by a vector
const VECTOR MATRIX::operator * ( const VECTOR& v ) const
{
	return( C[0]*v.x + C[1]*v.y + C[2]*v.z );
}

	//post-multiply by a matrix
const MATRIX MATRIX::operator * ( const MATRIX& m ) const
{
	return MATRIX( (*this) * m.C[0], (*this) * m.C[1], (*this) * m.C[2] );
}

//transpose
MATRIX MATRIX::transpose() const
{
	//turn columns on their side
	return MATRIX( VECTOR( C[0].x, C[1].x, C[2].x ), //column 0
		VECTOR( C[0].y, C[1].y, C[2].y ), //column 1
		VECTOR( C[0].z, C[1].z, C[2].z ) //column 2
		);
}

//scalar determinant
const SCALAR MATRIX::determinant() const
{
	//Lang, "Linear Algebra", p. 143
	return C[0].dot( C[1].cross(C[2]) );
}
