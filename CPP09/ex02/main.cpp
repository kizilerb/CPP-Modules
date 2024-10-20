#include "PmergeMe.hpp"


int main(int ac, char** arg){
	if(ac < 3){
		std::cout <<  "Please enter arguments in a right way.\n For Example: ./PmergeMe 3 5 9 7 4" << std::endl;
		return 1;
	}
	else{
		std::list<int> listShort;
		std::deque<int> dequeShort;
		arg++;
		float progressTimeList, progressTimeDeque;

		std::cout << "Before : ";
		for(int i = 0; arg[i] != 0; i++){
			std::cout << arg[i] << " ";
		}
		std::cout << std::endl;
		std::clock_t start = std::clock();
		if(listInValueDeque(dequeShort, arg)){
			mergeShortDeque(dequeShort, dequeShort.begin(), dequeShort.end());
			std::clock_t end = std::clock();
			progressTimeDeque = static_cast<float>(end - start) / (float)CLOCKS_PER_SEC * 10000;
		}
		else
			return 1;
		start = std::clock();
		if(listInValueList(listShort ,arg)){
			mergeShortList(listShort, listShort.begin(), listShort.end());
			std::clock_t end = std::clock();
			progressTimeList = static_cast<float>(end - start) / (float)CLOCKS_PER_SEC * 10000;
		}
		else
			return 1;

		std::cout << "After  : ";
		printList(listShort.begin(), listShort.end());
		std::cout << "Time to process a range of " << listShort.size() << " elements with std:list<int> : " << progressTimeList << " us." << std::endl;
		std::cout << "Time to process a range of " << dequeShort.size() << " elements with std:deque<int> : " << progressTimeDeque << " us." << std::endl;
	}
	return 0;
}
