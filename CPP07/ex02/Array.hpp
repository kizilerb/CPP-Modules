#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <cstdlib>

template <typename T>
class Array{
	private:
		T *array;
		unsigned int length;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T>& copy);
		Array& operator=(const Array& copy);
		T& operator[](unsigned int index);
		~Array();
		unsigned int size() const;
};

template <typename T>
Array<T>::Array() : length(1){
    this->array = new T();
}

template <typename T>
Array<T>::Array(unsigned int n): length(n) {
    if (n > 0)
        this->array = new T[n]();
    else {
        std::cout << "Created Empty Array" << std::endl;
        this->array = new T();
        this->length = 1;
    }
}

template <typename T>
Array<T>::Array(const Array<T>& copy){
    this->length = copy.length;
    this->array = new T[this->length];
    for(unsigned int i = 0; i < length ; i++)
        this->array[i] = copy.array[i];
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &copy) {
	if(this == &copy)
        return *this;
	if (this->array)
		delete [] this->array;
	this-> length = copy.length;
	this->array = new T[this->length];
	for (unsigned int i = 0; i < this->length; i++)
		this->array[i] = copy.array[i];
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int index){
	if (index < 0 || index >= this->size())
		throw std::out_of_range("Out of interval of the array.");
	else
		return this->array[index];
}

template<typename T>
Array<T>::~Array() {
	if (length != 0)
		delete [] this->array;
}

template <typename T>
unsigned int Array<T>::size() const{
    return this->length;
}
#endif
