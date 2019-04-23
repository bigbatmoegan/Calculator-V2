// -*- C++ -*-
// $Id: Array.h 380 2010-02-08 05:10:33Z hillj $

//==============================================================================
/**
 * @file       Array.h
 *
 * $Id: Array.h 380 2010-02-08 05:10:33Z hillj $
 *
 * Honor Pledge:
 *
 * I pledge that I have neither given nor received any help
 * on this assignment.
 */
//==============================================================================

#ifndef _ARRAY_H_
#define _ARRAY_H_

#include "Array_Base.h"

#include <cstring>          // for size_t definition
/**
	For this assignment, I decided that since the normal array should
	be able to do everything, and the fixed array was the only one with limitations,
	I decided to remove all resizing from base, and move them into here. This will
	allow the array to run everything from base array, and be able to grow and shrink
	as desired.
**/


/**
 * @class Array
 *
 * Basic implementation of a standard array class for chars.
 */
template <typename T>
class Array : public Array_Base <T>
{
public:
	//Default Constructor
	Array(void);

	//Constructor with length
	Array(size_t length);

	//Constructor with size and initial value
	Array(size_t length, T fill);

	//Copy Constructor
	Array(const Array & rhs);

	//Destructor
	~Array(void);
	
	/**
	 * Retrieve the current size of the array.
	 *
	 * @return          The current size
	 */
	size_t size(void) const;

	/**
	 * Retrieve the maximum size of the array.
	 *
	 * @return          The maximum size
	 */
	size_t max_size(void) const;


	/**
   * Set a new size for the array. If \a new_size is less than the current
   * size, then the array is truncated. If \a new_size if greater then the
   * current size, then the array is made larger and the new elements are
   * not initialized to anything. If \a new_size is the same as the current
   * size, then nothing happens.
   *
   * The array's original contents are preserved regardless of whether the
   * array's size is either increased or decreased.
   *
   * @param[in]       new_size              New size of the array
   */
	void resize(size_t new_size);

	// Shrink the array to reclaim unused space.
	void shrink(void);

private:
	/// Pointer to the actual data.
	T * data_;

	/// Current size of the array.
	size_t cur_size_;

	/// Maximum size of the array.
	size_t max_size_;


};

	// include the inline files
#include "Array.inl"

// include the source file since template class
#include "Array.cpp"

#endif  // !defined _CS507_ARRAY_H_