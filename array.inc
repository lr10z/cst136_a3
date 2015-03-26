//
// CST 136 - Assignment #3
//
// Author: Leander Rodriguez
//
// File: array.inc
//
// Due date:  Sunday, May 12th by 11:59pm
//



#include  <iostream>
#include  <string>
#include  <stdlib.h>


using  namespace  std;



//
// Array Class Constructor
//
template < class ELEMENT_TYPE >
Array<ELEMENT_TYPE>::Array( const int upperB, const int lowerB ) :
	m_upperBound( upperB ), 
	m_lowerBound( lowerB ),
	m_numElements( (m_upperBound - m_lowerBound) + 1 )
{
	
	//
	//  Checks if bounds are valid for use
	//
	if  ( m_upperBound >= m_lowerBound )
	{
		//
		// Allocates dynamic memory and checks for successful 
		// allocation
		//
		m_values  =  new  ELEMENT_TYPE[m_numElements];

		checkMEMallocation();
	}
	else
	{
		cout  <<  "Error, the upper bound is less than the lower bound!"  
			  <<  endl;

		exit( EXIT_FAILURE );
	}

}
	
	
	
//
// Copy constructor
//
template < class ELEMENT_TYPE >
Array< ELEMENT_TYPE >::Array( const Array &rhs ) : 
	m_upperBound( rhs.upperBound() ),
	m_lowerBound( rhs.lowerBound() ),
	m_numElements( rhs.numElements() ),
	m_values( rhs.m_values ),
	m_refCounter( rhs.m_refCounter )
{
}



//
// Destructor
//
template< class ELEMENT_TYPE >
Array< ELEMENT_TYPE >::~Array()
{
	if  ( m_refCounter.onlyInstance() )
	{
		delete [] m_values; 
	}
}



//
// Allows the caller to place an element value at a specific
// index position in the array
//
template < class ELEMENT_TYPE >
void Array< ELEMENT_TYPE >::set( const int indexPosition, ELEMENT_TYPE elementValue )
{
	m_values[indexPosition - m_lowerBound] = elementValue;
}



//
// Allows the caller to fetch an element value from a specific
// index position within the array
//
template < class ELEMENT_TYPE >
ELEMENT_TYPE Array< ELEMENT_TYPE >::get( const int indexPosition ) const
{
	return m_values[indexPosition - m_lowerBound];
}



//
// Checks if memory was successfully allocated
//
template < class ELEMENT_TYPE >
void Array< ELEMENT_TYPE >::checkMEMallocation() const
{
	if  ( ! m_values )
	{
		cout  <<  "Memory allocation failure!"  
				<<  endl;

		exit( EXIT_FAILURE );
	}
}



//
// SafeArray Class Constructor
//
template < class ELEMENT_TYPE >
SafeArray< ELEMENT_TYPE >::SafeArray( const int upperB, const int lowerB ) : 
	Array( upperB, lowerB )
{
}



//
// Allows the caller to place an element value at a specific
// index position in the array; if index position is valid
//
template < class ELEMENT_TYPE >
void SafeArray< ELEMENT_TYPE >::set( const int indexPosition, ELEMENT_TYPE elementValue)
{
	validateIndex( indexPosition );

	Array::set(  indexPosition, elementValue );
}



//
// Allows the caller to fetch an element value from a specific
// index position within the array; if index position is valid
//
template < class ELEMENT_TYPE >
ELEMENT_TYPE SafeArray< ELEMENT_TYPE >::get( const int indexPosition ) const
{
	validateIndex( indexPosition );

	return Array::get( indexPosition );
}



//
// Returns a reference to the element being modified; if index position is valid
//
template < class ELEMENT_TYPE >
ELEMENT_TYPE &SafeArray< ELEMENT_TYPE >::at( const int &indexPosition )
{ 
	validateIndex( indexPosition );

	return Array::at( indexPosition );
}



//
// Returns a reference to the element being modified; if index position is valid
// with respect to const
//
template < class ELEMENT_TYPE >
const ELEMENT_TYPE &SafeArray< ELEMENT_TYPE >::at( const int &indexPosition ) const 
{ 
	validateIndex( indexPosition );

	return Array::at( indexPosition );
}




//
// Verifies if an index value is within the valid range.
//
template < class ELEMENT_TYPE >
void  SafeArray< ELEMENT_TYPE >::validateIndex( int  indexPosition )  const
{
  if  ( indexPosition  <  lowerBound()  ||
        indexPosition  >  upperBound() )
  {
    cout  <<  "Index out of range"  <<  endl;

    exit( EXIT_FAILURE );
  }
}









