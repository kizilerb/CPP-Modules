#include "Span.hpp"

const char* Span::ArrayCapacityFull::what() const throw(){
	return "No more number can be added because the capacity is full.";
}

const char* Span::ValueisAvailable::what() const throw(){
	return "The value you want to add is already available.";
}

const char* Span::NotEnough::what() const throw(){
	return "There are not enough numbers in the number list for comparison.";
}
