#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(): cValue(0), iValue(0), fValue(0), dValue(0){}
ScalarConverter::ScalarConverter(const ScalarConverter& copy): cValue(copy.cValue), iValue(copy.iValue), fValue(copy.fValue), dValue(copy.dValue){}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy){
    if(this == &copy)
        return *this;
    this->cValue = copy.cValue;
    this->iValue = copy.iValue;
    this->fValue = copy.fValue;
    this->dValue = copy.dValue;
    return *this;
}
ScalarConverter::~ScalarConverter(){}
