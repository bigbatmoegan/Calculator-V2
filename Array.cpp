// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge: Jeremorg
//
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array_Base.h"
#include <stdexcept>         // for std::out_of_bounds exception
#include "Array.h"

//
// Default
//
template <typename T>
Array <T>::Array(void)
	:data_(new T[10]), cur_size_(0), max_size_(10)
{

}

//
// Constructor with size
//
template <typename T>
Array <T>::Array(size_t length)
	:data_(nullptr), cur_size_(0), max_size_(length)
{
	data_ = new T[length];
}

//
// Constructor with size and initial value
//
template <typename T>
Array <T>::Array(size_t length, T fill)
	:data_(nullptr), cur_size_(0), max_size_(length)
{
	data_ = new T[length];
	for (int i = 0; i < length; i++)
	{
		data_[i] = fill;
		cur_size_++;
	}
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array(const Array & array)
	:data_(new T[array.max_size()]), cur_size_(0), max_size_(array.max_size())
{
	int e = 0;
	for (int e = 0; e < max_size_; e++);
	{
		data_[e] = array[e];
		cur_size_++;
	}
}

//
// ~Array
//
template <typename T>
Array <T>::~Array(void)
{
	delete [] data_;
}

//
//resize
//
template <typename T>
void Array <T>::resize(size_t new_size)
{
	max_size_ = new_size;
}

//
//shrink
//
template <typename T>
void Array <T>::shrink(void)
{
	T *temp=new T[cur_size_];
	for(int a=0;a<cur_size_;a++)
	{
		temp[a]=data_[a];
	}
	max_size_=cur_size_;
	data_=temp;
	delete[] temp;
}