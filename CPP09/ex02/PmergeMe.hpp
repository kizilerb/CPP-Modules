#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <list>
#include <ctime>
#include <algorithm>
#include <sstream>

bool			listInValueList(std::list<int> &list, char **argList);
bool			listInValueDeque(std::deque<int> &list, char **argList);
void			printList(std::list<int>::iterator left, std::list<int>::iterator right);
void			printDeque(std::deque<int>::iterator left, std::deque<int>::iterator right);

//list
void			insertionSortList(std::list<int>::iterator left, std::list<int>::iterator right);
std::list<int>	mergeList(std::list<int> &left, std::list<int> &right);
void 			mergeShortList(std::list<int> &list, std::list<int>::iterator left, std::list<int>::iterator right);

void			insertionSortDeque(std::deque<int>::iterator left, std::deque<int>::iterator right);
std::deque<int>	mergeDeque(std::deque<int> &left, std::deque<int> &right);
void 			mergeShortDeque(std::deque<int> &list, std::deque<int>::iterator left, std::deque<int>::iterator right);

class InvalidArgument : public std::exception {
	public:
		virtual const char* what() const throw();
};
#endif
