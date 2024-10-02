#include "Span.hpp"

const char* Span::ArrayCapacityFull::what() const throw(){
	return "No more can be added as the capacity is full.";
}

const char* Span::ValueisAvailable::what() const throw(){
	return "The value you want to add is already available.";
}

const char* Span::NotEnough::what() const throw(){
	return "Not Enough Value in Number List";
}