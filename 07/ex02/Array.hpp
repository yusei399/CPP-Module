#ifndef ARRAY_HPP
#define ARRAY_HPP

# include <exception>
# include <stdexcept>
template <typename T>
class Array
{
	private:
		T	*_ptr;
		unsigned int	_n;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &copy);
		Array &operator=(const Array &rhs);
		int			size() const;
		T &operator[](unsigned int n);
		~Array();
};

template <typename T>
Array<T>::Array() : _ptr(NULL), _n(0){}

template <typename T>
Array<T>::Array(unsigned int n) : _ptr(new T[n]), _n(n) {}

template <typename T>
Array<T>::~Array()
{
	delete [] this->_ptr;
}

template <typename T>
Array<T>::Array(const Array &copy) :  _ptr(new T[copy._n]), _n(copy._n)
{
	for (size_t i = 0; i < copy._n; i++)
	{
		this->_ptr[i] = copy._ptr[i];
	}
}

template <typename T>
int	Array<T>::size() const
{
	return (this->_n);
}


template<typename T>
Array<T>	&Array<T>::operator=(const Array &rhs)
{
	for (size_t i = 0; i < this->_n && i < rhs._n; i++)
		this->_ptr[i] = rhs._ptr[i];
	return (*this);
}

template <typename T>
T	&Array<T>::operator[](unsigned int n)
{
	if (n >= this->_n)
		throw std::out_of_range("index out of bounds");
	return (this->_ptr[n]);
}

#endif

