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
	
	for(it_ptr = findArray.begin() ; it_ptr != findArray.end() ; it_ptr++)
		if(*it_ptr == findValue)
			return it_ptr;
	
	if(it_ptr == findArray.end())
		throw ErrorMessage();
	return it_ptr;
}

#endif