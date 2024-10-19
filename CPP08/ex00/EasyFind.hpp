#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>

class NotFound : public std::exception {
	public:
		virtual const char * what() const throw(){
			return ("The value you are looking for could not be found.");
		}
};

template <typename T>
typename T::iterator easyFind(T &array, int value){
	typename T::iterator it;
	it = find(array.begin(), array.end(), value);

	if(it == array.end())
		throw NotFound();
	return it;
}

#endif
