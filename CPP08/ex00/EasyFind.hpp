#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>

class ErrorMessage : public std::exception {
	public:
		virtual const char * what() const throw(){
			return "The value you are looking for was not found.";
		}
};

template <typename T>
typename T::iterator easyFind(T &findArray, int findValue){
	typename T::iterator	it_ptr;
	it_ptr = find(findArray.begin(), findArray.end(), findValue);
	
	if(it_ptr == findArray.end())
		throw ErrorMessage();
	return it_ptr;
}

#endif