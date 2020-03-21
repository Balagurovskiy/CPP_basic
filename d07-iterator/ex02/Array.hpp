
#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template <typename T>
class Array
{
	private:
		T * 			_data;
		unsigned int 	_size;
	public:
		Array<T>(void){
			_data = NULL;
			_size = 0;
		}
		Array<T>(unsigned int size){
			if (size < 0)
				throw std::exception();
			_size = size;
			_data = new T[_size];
		}
		Array<T>(Array const & a){
			*this = a;
		}

		Array<T> & operator =
					(Array const & a)
		{
			if (a._data == NULL || a._size < 0)
				throw std::exception();
			else{
				_size = a._size;
				delete _data;
				_data = new T[_size];
				int i = -1;
				while(++i < _size)
					_data[i] = a._data[i];
			}
		}
		T & operator []
				(unsigned int size)
		{
			if (_size <= size || size < 0)
				throw std::exception();
			return (_data[size]);
		}
		unsigned int size() const
		{
			return _size;
		}
};

# endif