#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <list>
#include <ctime>
#include <algorithm>
#include <sstream>

bool			anyLetter(std::string input);

class InvalidArgument : public std::exception {
	public:
		virtual const char* what() const throw();
};

template <typename Iterator>
void printTemplate(Iterator left, Iterator right){
	while(left != right){
		std::cout << *left << " ";
		left++;
	}
	std::cout << std::endl;
}

template <typename T>
bool listInValueTemplate(T &list, char **argList){
	int value = 0;
	try{
		for(size_t i = 0; argList[i] != 0; i++ ){
			if(!anyLetter(argList[i]))
				throw InvalidArgument();
			std::istringstream iss(argList[i]);
			iss >> value;
			list.push_back(value);
		}
	}catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
        return false;
    }
	return true;
}

template<typename Iterator>
void insertionSortTemplate(Iterator left, Iterator right) {
    if (left == right) // Eğer sıralanacak eleman yoksa işlem yapma
        return;
	for(Iterator i = std::next(left); i != right; ++i){
    	Iterator j = std::prev(i);
		int key = *i;
		while(j != std::prev(left) && key < *j){
			*std::next(j) = *j;
			j--;
		}
		*std::next(j) = key;
	}
}

template<typename T>
T mergeTemplate(T &left, T &right){
	T mergeSorted;
	typename T::iterator itLeft = left.begin();
	typename T::iterator itRight = right.begin();

	while(itLeft != left.end() && itRight != right.end()){
		if(*itLeft <= *itRight){
			mergeSorted.push_back(*itLeft);
			itLeft++;
		}
		else{
			mergeSorted.push_back(*itRight);
			itRight++;
		}
	}
	while (itLeft != left.end()) {
		mergeSorted.push_back(*itLeft);
		++itLeft;
	}

    while (itRight != right.end()) {
        mergeSorted.push_back(*itRight);
        ++itRight;
    }
	return mergeSorted;
}


template<typename T, typename Iterator>
void mergeShortTemplate(T &list, Iterator left, Iterator right){
	if (std::distance(left, right) <= 1)
		return;

    if (std::distance(left, right) < 10) {
        insertionSortTemplate(left, right);
        return;
    }

	Iterator mid = std::next(left, std::distance(left, right) / 2);
	mergeShortTemplate(list, left, mid);
	mergeShortTemplate(list, mid, right);

	T leftMerge(left,mid);
	T rightMerge(mid, right);

	T sorted = mergeTemplate(leftMerge, rightMerge);
	std::copy(sorted.begin(), sorted.end(), left);
}

#endif
