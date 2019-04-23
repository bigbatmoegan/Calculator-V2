// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
	return cur_size_;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
	if(cur_size_==0)
	{
		//throw empty_exception ("stack is empty");
	}
	else
	{
		return data_[cur_size_-1];
	}
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
	for(int i=0;i<max_size_;i++)
	{
		if(data_[i]!=NULL)
		{
			return false;
		}
		else if(i+1==max_size_ && data_[i]!=NULL)
		{
			return true;
		}
		else
		{
			//just keep going
		}
	}
}
