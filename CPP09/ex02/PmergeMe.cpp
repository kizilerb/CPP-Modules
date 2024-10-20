#include "PmergeMe.hpp"

const char* InvalidArgument::what() const throw(){
	return "Invalid argument: not a number";
}

bool anyLetter(std::string input){
	for (size_t i = 0; i < input.size(); ++i) {
		if(i == 0 && (input[i] == '+' || input[i] == '-'))
			i++;
		if (!std::isdigit(input[i]))
			return false;
	}
	return true;
}

//DEQUE FUNCTIONS

bool getValueDeque(std::deque<int> &list, char **argList){
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

void mergeShortDeque(std::deque<int> &list, std::deque<int>::iterator left, std::deque<int>::iterator right){
	if (std::distance(left, right) <= 1)
        return;

    if (std::distance(left, right) < 10) {
        insertionSortDeque(left, right);
        return;
    }

	std::deque<int>::iterator mid = std::next(left, std::distance(left, right) / 2);
	mergeShortDeque(list, left, mid);
	mergeShortDeque(list, mid, right);

	std::deque<int> leftMerge(left,mid);
	std::deque<int> rightMerge(mid, right);
	std::deque<int> sorted = mergeDeque(leftMerge, rightMerge);

	std::copy(sorted.begin(), sorted.end(), left);
}

void insertionSortDeque(std::deque<int>::iterator left, std::deque<int>::iterator right) {
    if (left == right)
        return;
	for(std::deque<int>::iterator i = std::next(left); i != right; ++i){
    	std::deque<int>::iterator j = std::prev(i);
		int key = *i;
		while(j != std::prev(left) && key < *j){
			*std::next(j) = *j;
			j--;
		}
		*std::next(j) = key;
	}
}

std::deque<int> mergeDeque(std::deque<int> &left, std::deque<int> &right){
	std::deque<int> mergeSorted;
	std::deque<int>::iterator itLeft = left.begin();
	std::deque<int>::iterator itRight = right.begin();

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

void printDeque(std::deque<int>::iterator left, std::deque<int>::iterator right){
	while(left != right){
		std::cout << *left << " ";
		left++;
	}
	std::cout << std::endl;
}

//LIST FUNCTIONS

void insertionSortList(std::list<int>::iterator left, std::list<int>::iterator right) {
    if (left == right)
        return;
	for(std::list<int>::iterator i = std::next(left); i != right; ++i){
    	std::list<int>::iterator j = std::prev(i);
		int key = *i;
		while(j != std::prev(left) && key < *j){
			*std::next(j) = *j;
			j--;
		}
		*std::next(j) = key;
	}
}

std::list<int> mergeList(std::list<int> &left, std::list<int> &right){
	std::list<int> mergeSorted;
	std::list<int>::iterator itLeft = left.begin();
	std::list<int>::iterator itRight = right.begin();

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

bool getValueList(std::list<int> &list, char **argList){
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

void mergeShortList(std::list<int> &list, std::list<int>::iterator left, std::list<int>::iterator right){
	 if (std::distance(left, right) <= 1)
        return;

    if (std::distance(left, right) < 10) {
        insertionSortList(left, right);
        return;
    }

	std::list<int>::iterator mid = std::next(left, std::distance(left, right) / 2);
	mergeShortList(list, left, mid);
	mergeShortList(list, mid, right);

	std::list<int> leftMerge(left,mid);
	std::list<int> rightMerge(mid, right);
	std::list<int> sorted = mergeList(leftMerge, rightMerge);

	std::copy(sorted.begin(), sorted.end(), left);
}

void printList(std::list<int>::iterator left, std::list<int>::iterator right){
	while(left != right){
		std::cout << *left << " ";
		left++;
	}
	std::cout << std::endl;
}
