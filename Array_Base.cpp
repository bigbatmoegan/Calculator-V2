

#include "Array_Base.h"

#include <stdexcept>         // for std::out_of_bounds exception

//
// Array
//
template <typename T>
Array_Base <T>::Array_Base(void)
	:data_(new T[10]), cur_size_(0), max_size_(10)
{

}

//
// Array (size_t)
//
template <typename T>
Array_Base <T>::Array_Base(size_t length)
	:data_(nullptr), cur_size_(0), max_size_(length)
{
	if(length>0)
	{
		data_ = new T[length];
	}
	else
	{
		//Dont create an array with negative or 0 size
	}
}

//
// Array (size_t, char)
//
template <typename T>
Array_Base <T>::Array_Base(size_t length, T fill)
	:data_(new T[length]), cur_size_(0), max_size_(length)
{
	data_[cur_size_] = fill;
	cur_size_++;
}

//
// Array (const Array &)
//
template <typename T>
Array_Base <T>::Array_Base(const Array_Base & array)
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
Array_Base <T>::~Array_Base(void)
{
	delete[] data_;
}

//
// operator =
//
template <typename T>
const Array_Base <T> & Array_Base <T>::operator = (const Array_Base & rhs)
{
	cur_size_ = rhs.size();
	max_size_ = rhs.max_size();
	for (int a = 0; a < cur_size_; a++)
	{
		data_[a] == rhs[a];
	}
}

//
// operator []
//
template <typename T>
T & Array_Base <T>::operator [] (size_t index)
{
	if (index<0 || index>max_size_)
	{
		throw std::out_of_range("out of range");
	}
	else
	{
		return data_[index];
	}
}

//
// operator [] 
//
template <typename T>
const T & Array_Base <T>::operator [] (size_t index) const
{
	if (index<0 || index>max_size_)
	{
		throw std::out_of_range("out of range");
	}
	else
	{
		return data_[index];
	}
}

//
// get
//
template <typename T>
T Array_Base <T>::get(size_t index) const
{
	if (index<0 || index>max_size_)
	{
		throw std::out_of_range("out of range");
	}
	else
	{
		return data_[index];
	}
}

//
// set
//
template <typename T>
void Array_Base <T>::set(size_t index, T value)
{
	if (index<0 || index>max_size_)
	{
		throw std::out_of_range("out of range");
	}
	else
	{
		data_[index] = value;
	}
}

//
// find (char)
//
template  <typename T>
int Array_Base <T>::find(T value) const
{
	for (int b = 0; b < cur_size_; b++)
	{
		if (data_[b] == value)
		{
			return b;
		}
		else if (data_[b] != value && b + 1 == cur_size_)
		{
			//character not in array
			return -1;
		}
		else
		{
			//just go through loop again
		}
	}
}

//
// find (char, size_t) 
//
template <typename T>
int Array_Base <T>::find(T val, size_t start) const
{
	for (int c = start; c < cur_size_; c++)
	{
		if (data_[c] == val)
		{
			return c;
		}
		else if (data_[c] != val && c + 1 == cur_size_)
		{
			//character not in array
			return -1;
		}
		else
		{
			//just go through loop again
		}
	}
}

//
// operator ==
//
template <typename T>
bool Array_Base <T>::operator == (const Array_Base & rhs) const
{
	if (data_ == rhs)
	{
		return true;

	}
	if (cur_size_ != rhs.size())
	{
		return false;
	}
	for (int i = 0; i < cur_size_; i++)
	{
		if (data_[i] != rhs[i])
		{
			return false;
		}
		else if (i + 1 == cur_size_ && data_[i] == rhs[i])
		{
			return true;
		}
	}
}

//
// operator !=
//
template <typename T>
bool Array_Base <T>::operator != (const Array_Base & rhs) const
{
	if (data_ != rhs)
	{
		return true;

	}
	if (cur_size_ != rhs.size())
	{
		return true;
	}
	for (int i = 0; i < cur_size_; i++)
	{
		if (data_[i] == rhs[i])
		{
			return false;
		}
		else if (i + 1 == cur_size_ && data_[i] != rhs[i])
		{
			return true;
		}
	}
}

//
// fill
//
template <typename T>
void Array_Base <T>::fill(T element)
{
	if(cur_size_<max_size_)
	{
		data_[cur_size_] = element;
		cur_size_++;
	}
}

//
//reverse
//
template <typename T>
void Array_Base <T>::reverse(void)
{
	int begin=0;
	int end=cur_size_-1;
	T temp;
	while(begin<end)
	{
		temp=data_[begin];
		data_[begin]=data_[end];
		data_[end]=temp;
		begin++;
		end--;
	}

}

//
// slice
//
template <typename T>
void Array_Base <T>::slice(size_t begin) const
{
	T *temp=new T[cur_size_-begin];
	for(int a=begin;a<cur_size_;a++)
	{
		temp[a]=data_[a];
	}
	max_size_=cur_size_-begin;
	data_=temp;
	delete[] temp;
}

//
// slice
//
template <typename T>
void Array_Base <T>::slice(size_t begin, size_t end) const
{
	T *temp=new T[cur_size_-begin-end];
	for(int a=begin;a<end;a++)
	{
		temp[a]=data_[a];
	}
	max_size_=cur_size_-begin-end;
	data_=temp;
	delete[] temp;
}