// VECTOR.cpp: implementation of the VECTOR class.
//
//////////////////////////////////////////////////////////////////////

#include <cmath>

#include "VECTOR.h"

// This class VECTOR comes from an article about rigid body
// animation published on www.gamasutra.com so it may
// follow its own license. Please check gamasutra at
// http://www.gamasutra.com/features/19990702/data_structures_01.htm
// or just write your own to replace it.


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

SCALAR& VECTOR::operator [] ( const long i )
{
	return *((&x) + i);
}

//compare

const bool VECTOR::operator == ( const VECTOR& v ) const
{
	return (v.x==x && v.y==y && v.z==z);
}

const bool VECTOR::operator != ( const VECTOR& v ) const
{
	return !(v == *this);
}

//negate

const VECTOR VECTOR::operator - () const
{
	return VECTOR( -x, -y, -z );
}

//assign

const VECTOR& VECTOR::operator = ( const VECTOR& v )
{
	x = v.x;
	y = v.y;
	z = v.z;
	return *this;
}

//increment

const VECTOR& VECTOR::operator += ( const VECTOR& v ) 
{
	x+=v.x;
	y+=v.y;
	z+=v.z;
	return *this;
} 

//decrement

const VECTOR& VECTOR::operator -= ( const VECTOR& v ) 
{
	x-=v.x;
	y-=v.y;
	z-=v.z;
	return *this;
} 

//self-multiply
const VECTOR& VECTOR::operator *= ( const SCALAR& s )
{
	x*=s;
	y*=s;
	z*=s;
	return *this;
}

//self-divide
const VECTOR& VECTOR::operator /= ( const SCALAR& s )
{
	const SCALAR r = 1 / s;
	x *= r;
	y *= r;
	z *= r;
	return *this;
}

//add

const VECTOR VECTOR::operator + ( const VECTOR& v ) const
{
	return VECTOR(x + v.x, y + v.y, z + v.z);
}

//subtract

const VECTOR VECTOR::operator - ( const VECTOR& v ) const
{
	return VECTOR(x - v.x, y - v.y, z - v.z);
}

//post-multiply by a scalar

const VECTOR VECTOR::operator * ( const SCALAR& s ) const
{
	return VECTOR( x*s, y*s, z*s );
}

//divide

const VECTOR VECTOR::operator / (SCALAR s) const
{
	s = 1/s;
	return VECTOR( s*x, s*y, s*z );
}

//cross product

const VECTOR VECTOR::cross( const VECTOR& v ) const
{
	//Davis, Snider, "Introduction to Vector Analysis", p. 44
	return VECTOR( y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.x );
}

//scalar dot product

const SCALAR VECTOR::dot( const VECTOR& v ) const
{
	return x*v.x + y*v.y + z*v.z;
}

//length

const SCALAR VECTOR::length() const
{
	return (SCALAR)sqrt( (double)this->dot(*this) );
}

//unit vector

const VECTOR VECTOR::unit() const
{
	return (*this) / length();
}

//make this a unit vector

void VECTOR::normalize()
{
	(*this) /= length();
}

//equal within an error e

const bool VECTOR::nearlyEquals( const VECTOR& v, const SCALAR e ) const
{
	return fabs(x-v.x)<e && fabs(y-v.y)<e && fabs(z-v.z)<e;
}
