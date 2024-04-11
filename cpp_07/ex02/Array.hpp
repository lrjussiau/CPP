#ifndef ARRAY_H
# define ARRAY_H

#include <iostream>
#include <stdexcept> 

class OutOfBoundsException : public std::exception {
	public:
		virtual const char *what() const throw () {
			return ("Index is out of bounds");
		}
};

template <typename T>
class Array {

	private:

		T*				_array;
		unsigned int	_size;
	
	public:
		
		Array() : _array(new T[0]) , _size(0) {};

		Array(unsigned int size) : _array(new T[size]) , _size(size) {};

		virtual ~Array() {
			delete [] _array;
		};

		Array(const Array &src) : _array(new T[src.size]) , _size(src.size) {
			for (unsigned i = 0; i < _size; i++) {
				src._array[i] = _array[i];
			}
		};

		Array &operator=(const Array &src) {
			if ( this != &src ) {
				delete [] _array;
				_array = new T[src.size()];
				_size = src._size;
				for ( unsigned int i = 0; i < _size; i++ )
					_array[i] = src._array[i];
			}
			return *this;
		};

		T &operator[](unsigned int index) const {
			if (index >= _size) {
				throw OutOfBoundsException();
			}
        	return _array[index];
		};

		unsigned int	size() const {
			return _size;
		};
};

template <typename T>
std::ostream &  operator<<(std::ostream & o, const Array<T>& rhs) {
	for (unsigned i = 0; i < rhs.size(); i++) {
		o << rhs[i] << " ";
	}
	return o;
}

#endif