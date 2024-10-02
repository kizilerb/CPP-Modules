#include "Span.hpp"

Span::Span(): arraySize(0){
    std::cout << " Default Constructor Called" << std::endl;
}

Span::Span(int _arraySize): arraySize(_arraySize){
    std::cout << "Constructor Called" << std::endl;
}

Span::Span(const Span& copy): arraySize(copy.arraySize){
    std::cout << "Copy Constructor Called" << std::endl;
    std::set<int>::iterator itPtr = copy.spanSet.begin();
    this->spanSet.clear();
    for(; itPtr != copy.spanSet.end(); itPtr++)
        this->spanSet.insert(*itPtr);
}

Span::~Span(){
    std::cout << "Destructor Called" << std::endl;
}

Span& Span::operator=(const Span& copy){
    std::cout << "Assigment Copy Operator Called" << std::endl;
    if (this == &copy)
        return *this;
    this->arraySize = copy.arraySize;
    std::set<int>::iterator itPtr = copy.spanSet.begin();
    this->spanSet.clear();
    for(; itPtr != copy.spanSet.end(); itPtr++)
        this->spanSet.insert(*itPtr);
    return *this;
}

void Span::printSpan(){
    std::set<int>::iterator it = this->spanSet.begin();
    for(int i = 1 ; it != this->spanSet.end(); it++, i++)
        std::cout << "Span[" << i << "] Numbers : " << *it << std::endl;
}

 void Span::addNumber(int value){
    try{
        if(this->spanSet.size() == this->arraySize)
            throw ArrayCapacityFull();
        else if(*this->spanSet.find(value) == value)
            throw ValueisAvailable();
        else
            this->spanSet.insert(value);
    }catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    } 
 }

int Span::longestSpan(){
    try{
        if(this->spanSet.size() <= 2)
            throw NotEnough();
        return *(std::prev(this->spanSet.end())) - *this->spanSet.begin();
    }catch(std::exception &e){
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

int Span::shortestSpan(){
    try{
        if(this->spanSet.size() <= 2)
            throw NotEnough();
        std::set<int>::iterator itFirst = this->spanSet.begin();
        std::set<int>::iterator itNext = std::next(itFirst);

        int minSpan = *itNext - *itFirst;
        for(; itNext != this->spanSet.end() ; itNext++, itFirst++){
            int span = *itNext - *itFirst;
            if(span < minSpan)
                minSpan = span;
        }
        return minSpan;
    }catch(std::exception &e){
        std::cerr << e.what() << std::endl;
    }
    return 0;
}