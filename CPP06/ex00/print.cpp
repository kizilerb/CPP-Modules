 #include "ScalarConverter.hpp"

const char * ScalarConverter::InvalidArgument::what() const throw(){
	return ("Invalid Input!"); 
}

void ScalarConverter::resultPrintChar(bool anyInfinity){
	if(!isprint(this->cValue) && anyInfinity == true)
		std::cout << "char : imposible" << std::endl;
	else if(!isprint(this->cValue))
		std::cout << "char : non displayable" << std::endl;
	else
		std::cout << "char : '" << this->cValue << "'" << std::endl;
}

void ScalarConverter::resultPrintInt(bool anyInfinity){
	if(anyInfinity == true)
		std::cout << "int : imposible" << std::endl;
    else if (this->dValue > INT_MAX || this->dValue < INT_MIN)
		std::cout << "int : imposible" << std::endl;
    else
        std::cout << "int : " << this->iValue << std::endl;
}

void ScalarConverter::resultPrintFloatDouble(std::string input, std::string type, bool anyInfinity){
    if(anyInfinity == false && (type == "FLOAT" || type == "DOUBLE")){
        std::string pos = "";
        std::string zeros = "";
        if (input.find('.') + 1 != input.size() && input[input.find('.') + 1] != 'f'){
            pos = input.substr(input.find('.') + 1, input.length());
            zeros = std::string(pos.length() - 1, '0');
        }
        if(pos == "" || pos == zeros + "0" || pos == zeros + "f")
        {
            std::cout << "float : " << this->fValue << ".0f" << std::endl;
            std::cout << "double : " << this->dValue << ".0" << std::endl;
        }
        else{
            std::cout << "float : " << this->fValue << "f" << std::endl;
            std::cout << "double : " << this->dValue << std::endl;
        }
    }
    else if(anyInfinity == false && (type != "FLOAT" && type != "DOUBLE")){
        std::cout << "float : " << this->fValue << ".0f" << std::endl;
        std::cout << "double : " << this->dValue << ".0" << std::endl;
    }
    else if (!input.compare("nan") || !input.compare("nanf")){
        std::cout << "float : " << "nanf" << std::endl;
        std::cout << "double : " << "nanf" << std::endl;
    }
    else if (!input.compare("+inf") || !input.compare("+inff")){
         std::cout << "float : " << "+inff" << std::endl;
         std::cout << "dobule : " << "+inff" << std::endl;
    }
    else if (!input.compare("-inf") || !input.compare("-inff")){
         std::cout << "dobule : " << "-inff" << std::endl;
         std::cout << "dobule : " << "-inff" << std::endl;
    }
}