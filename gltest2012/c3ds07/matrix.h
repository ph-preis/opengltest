// MATRIX.h: interface for the MATRIX class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(MATRIX_H__INCLUDED_)
#define MATRIX_H__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

// This class MATRIX comes from an article about rigid body
// animation published on www.gamasutra.com so it may
// follow its own license. Please check gamasutra at
// http://www.gamasutra.com/features/19990702/data_structures_01.htm
// or just write your own to replace it.

class MATRIX
{
public:
	VECTOR C[3]; //column vectors
public:
	MATRIX();
	MATRIX( const VECTOR& c0, const VECTOR& c1, const VECTOR& c2 );
	//index a column, allow assignment
	//NOTE: using this index operator along with the vector index
	//gives you M[column][row], not the standard M[row][column]
	VECTOR& operator [] ( long i );
	//compare
	const bool operator == ( const MATRIX& m ) const;

	const bool operator != ( const MATRIX& m ) const;

	//assign
	const MATRIX& operator = ( const MATRIX& m );

	//increment
	const MATRIX& operator +=( const MATRIX& m );

	//decrement
	const MATRIX& operator -=( const MATRIX& m );

	//self-multiply by a scalar
	const MATRIX& operator *= ( const SCALAR& s );

	//self-multiply by a matrix
	const MATRIX& operator *= ( const MATRIX& m );

	//add
	const MATRIX operator + ( const MATRIX& m ) const;

	//subtract
	const MATRIX operator - ( const MATRIX& m ) const;

	//post-multiply by a scalar
	const MATRIX operator * ( const SCALAR& s ) const;

	//pre-multiply by a scalar
	friend inline const MATRIX operator * ( const SCALAR& s, const MATRIX& m )
	{
		return m * s;
	}

	//post-multiply by a vector
	const VECTOR operator * ( const VECTOR& v ) const;

	//pre-multiply by a vector
	inline friend const VECTOR operator * ( const VECTOR& v, const MATRIX& m )
	{
		return VECTOR( m.C[0].dot(v), m.C[1].dot(v), m.C[2].dot(v) );
	}

	//post-multiply by a matrix
	const MATRIX operator * ( const MATRIX& m ) const;

	//transpose
	MATRIX transpose() const;

	//scalar determinant
	const SCALAR determinant() const;

	//matrix inverse
	const MATRIX inverse() const;
};

#endif // !defined(MATRIX_H__INCLUDED_)
