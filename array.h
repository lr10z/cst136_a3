//
// CST 136 - Assignment #3
//
// Author: Leander Rodriguez
//
// File: array.h
//
// Due date:  Sunday, May 12th by 11:59pm
//



#ifndef  array_H
#define  array_H


#include  "refCounter.h"


/*
* Constraints for the TYPE datatype for the Array<> template class:
*
*   - ELEMENT_TYPE must have a default Constructor
*   - ELEMENT_TYPE must be assignable
*   - ELEMENT_TYPE must be copyable
*
*/

//
// Parent class
//
template< class ELEMENT_TYPE >
class  Array
{

  public  :

	//
	// Constructor
	//
	Array( const int upperB, const int lowerB = 0 );
	Array( const Array &rhs );
	~Array();


	//
	// Methods
	//
	void set( const int indexPosition, const ELEMENT_TYPE elementValue );
	
	ELEMENT_TYPE get( const int indexPosition ) const;

		  ELEMENT_TYPE &at( const int &indexPosition )		 { return m_values[ indexPosition ]; }
	const ELEMENT_TYPE &at( const int &indexPosition ) const { return m_values[ indexPosition ]; }
	
	int lowerBound() const { return  m_lowerBound; }
	int upperBound() const { return m_upperBound; }

	unsigned numElements() const { return  m_numElements; }
	unsigned size() const		 { return  m_numElements * sizeof( ELEMENT_TYPE ); }


  private  :

    //
	// Member variables
	//
	const int			m_upperBound;
	const int			m_lowerBound;
	const unsigned int	m_numElements;
	ELEMENT_TYPE		*m_values;

	RefCounter			m_refCounter;


	//
	// Methods
	//
	void checkMEMallocation() const;

};



/*
* Constraints for the TYPE datatype for the SafeArray<> template class:
*
*   - ELEMENT_TYPE must have a default Constructor
*   - ELEMENT_TYPE must be assignable
*   - ELEMENT_TYPE must be copyable
*
*/

//
// Child class, allows for additional functionality with
// index bound checking
//
template< class ELEMENT_TYPE >
class  SafeArray : public Array<ELEMENT_TYPE>
{

  public  :


	//
	// Constructor
	//
	SafeArray( int upperB, int lowerB = 0 );
	

	//
	// Methods
	//
	void set( const int indexPosition, const ELEMENT_TYPE elementValue );
	
	ELEMENT_TYPE get( const int indexPosition ) const;

		  ELEMENT_TYPE &at( const int &indexPosition );
	const ELEMENT_TYPE &at( const int &indexPosition ) const;


  private  :

    void  validateIndex( int  indexPosition )  const;
	 
};



//
// Implementation of Template file
//
#include "array.inc"



#endif
