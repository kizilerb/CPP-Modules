#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <algorithm>
# include <stack>
# include <list>
# include <vector>
# include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>(){}
		MutantStack(const MutantStack &other) : std::stack<T>(other){}
		MutantStack &operator=(const MutantStack &other){
			std::stack<T>::operator=(other);
			return *this;
		}
		~MutantStack(){}

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin(){
			return std::stack<T>::c.begin(); 
		}

		iterator end(){ 
			return std::stack<T>::c.end(); 
		}
};

#endif