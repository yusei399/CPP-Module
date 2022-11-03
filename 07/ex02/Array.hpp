#ifndef ARRAY_HPP
#define ARRAY_HPP


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
Array<T>::Array(unsigned int _n) : _ptr(new T[n]), _n(n) {}

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



#endif

