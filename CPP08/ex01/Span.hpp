#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <set>
#include <stack>
#include <algorithm>
#include <vector>

class Span{
    private:
        std::set<int, std::less<int> >   spanSet;
        size_t                          arraySize;

    public:
        Span();
        Span(int _arraySize);
        Span(const Span& copy);
        Span& operator=(const Span& copy);
        ~Span();

        void    printSpan();
        void    addNumber(int value);
        int     shortestSpan();
        int     longestSpan();

        template <typename T>
        void     addNumbers(T &list){
            try{
                size_t listSize = std::distance(list.begin(), list.end());

                int maxAddCount = this->arraySize - this->spanSet.size();
                int oldNumberCount = this->spanSet.size();
                int addedCount = 0;
                typename T::iterator itList = list.begin();
                for(;itList != list.end() && addedCount != maxAddCount; itList++){
                    try{
                        if(*this->spanSet.find(*itList) == *itList)
                            throw ValueisAvailable();
                        this->spanSet.insert(*itList);
                        addedCount++;
                    }catch(std::exception &e){
                        std::cerr << e.what() << std::endl;
                    }
                }
                if(listSize + oldNumberCount > this->arraySize){
                    std::cout << "Added Count : 0 - " << addedCount << " | Input List Full Size : " << listSize << std::endl;
                    throw ArrayCapacityFull();
                }
                else
                    std::cout << "Added All List" << std::endl;
            }catch(std::exception &e){
                std::cerr << e.what() << std::endl;
            }
        }

        //Exception
        class ArrayCapacityFull : public std::exception{
            public:
                virtual const char* what() const throw();
        };

        class ValueisAvailable : public std::exception{
            public:
                virtual const char* what() const throw();
        };

        class NotEnough : public std::exception{
            public:
                virtual const char* what() const throw();
        };
};

#endif