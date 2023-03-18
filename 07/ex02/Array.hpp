#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
# include <exception>
# include <stdexcept>

template <typename T>
class Array
{
	private:
		T	*_ptr;
		unsigned int	_n;
	public:
		Array() : _ptr(0), _n(0)
		{
			std::cout << "Default constructor called" << std::endl;
		}

		Array(unsigned int n) : _ptr(new T[n]), _n(n)
		{
			std::cout << "Constructor called" << std::endl;
		}

		~Array()
		{
			delete [] this->_ptr;
		}

		Array(const Array &copy) :  _ptr(new T[copy._n]), _n(copy._n)
		{
			std::cout << "Copy constructor called" << std::endl;
			for (size_t i = 0; i < copy._n; i++)
				this->_ptr[i] = copy._ptr[i];
		}

		unsigned int	size() const
		{
			return (this->_n);
		}

		Array	&operator=(const Array &rhs)
		{
			if (this != &rhs)
			{
				for (size_t i = 0; i < this->_n && i < rhs._n; i++)
					this->_ptr[i] = rhs._ptr[i];
			}
			return (*this);
		}

		T	&operator[](unsigned int n)
		{
			if (n >= this->_n)
				throw std::out_of_range("index out of range");
			return (this->_ptr[n]);
		}
};

#endif

