// VECTOR.h: interface for the VECTOR class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(VECTOR_H__INCLUDED_)
#define VECTOR_H__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// This class VECTOR comes from an article about rigid body
// animation published on www.gamasutra.com so it may
// follow its own license. Please check gamasutra at
// http://www.gamasutra.com/features/19990702/data_structures_01.htm
// or just write your own to replace it.

// A floating point number
//

typedef float SCALAR;

//
// A 3D vector
//

class VECTOR
{
public:
	SCALAR	x, y, z; //x,y,z coordinates
public:
	VECTOR() : x(0), y(0), z(0) {}

	VECTOR( const SCALAR& a, const SCALAR& b, const SCALAR& c ) : x(a), y(b), z(c) {}

	//index a component
	//NOTE: returning a reference allows
	//you to assign the indexed element

	SCALAR& operator [] ( const long i );

//compare

	const bool operator == ( const VECTOR& v ) const;

	const bool operator != ( const VECTOR& v ) const;

//negate

	const VECTOR operator - () const;

//assign

	const VECTOR& operator = ( const VECTOR& v );

//increment

	const VECTOR& operator += ( const VECTOR& v );

//decrement

	const VECTOR& operator -= ( const VECTOR& v );

//self-multiply
	const VECTOR& operator *= ( const SCALAR& s );

//self-divide
	const VECTOR& operator /= ( const SCALAR& s );

//add

	const VECTOR operator + ( const VECTOR& v ) const;

//subtract

	const VECTOR operator - ( const VECTOR& v ) const;

//post-multiply by a scalar

	const VECTOR operator * ( const SCALAR& s ) const;

//pre-multiply by a scalar

	friend inline const VECTOR operator * ( const SCALAR& s, const VECTOR& v )
	{
		return v * s;
	}

//divide

	const VECTOR operator / (SCALAR s) const;

//cross product

	const VECTOR cross( const VECTOR& v ) const;

//scalar dot product

	const SCALAR dot( const VECTOR& v ) const;

//length

	const SCALAR length() const;

//unit vector

	const VECTOR unit() const;

//make this a unit vector

	void normalize();

//equal within an error e

	const bool nearlyEquals( const VECTOR& v, const SCALAR e ) const;
};

#endif // !defined(VECTOR_H__INCLUDED_)
