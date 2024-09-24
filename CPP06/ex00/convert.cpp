#include "ScalarConverter.hpp"

std::string ScalarConverter::getType(const std::string input){
    std::string type;
    try{
		if(input.length() == 0)
			return "empty";
		else if((input.compare("nan") == 0) || (input.compare("+inf") == 0) || (input.compare("-inf") == 0)
			|| (input.compare("-inff") == 0) || (input.compare("+inff") == 0) || (input.compare("nanf") == 0))
			type = "infinity";
		else if(input.length() == 1 && !std::isdigit(input[0]))
			type = "CHAR";
        else if (std::count(input.begin(), input.end(), '.') == 1 ){
			if (input[input.length() - 1] == 'f' && std::count(input.begin(), input.end(), 'f') == 1){
				type = "FLOAT";
				if(ScalarConverter::anyLetter(input, type))
					this->fValue = std::stof(input);
				else
					throw InvalidArgument();
			}
			else {
				type = "DOUBLE";
				if(ScalarConverter::anyLetter(input, type))
					this->dValue = std::stod(input);
				else
					throw InvalidArgument();
			}
		}
        else {
			type = "INT";
			if(ScalarConverter::anyLetter(input , type) == true)
				this->iValue = std::stoi(input);
			else
				throw InvalidArgument();
		}
	}
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
		return "Argument Error";
    }
    catch (const std::out_of_range& e){
		std::cout << type << " : <" << input << "> out of range " << std::endl;
		return "Out Of Range";
	}
	return type;
}

bool ScalarConverter::anyLetter(std::string input, std::string type){
    for (size_t i = 0; i < input.size(); ++i) {
		if(i == 0 && (input[i] == '+' || input[i] == '-'))
			i++;
		if (type == "INT" && !std::isdigit(input[i]))
			return false;
		else if (type == "FLOAT" && (input[i] != '.' && input[i] != 'f') && !std::isdigit(input[i]))
			return false;
		else if (type == "DOUBLE" && (input[i] != '.' && !std::isdigit(input[i])))
			return false;
	}
	return true;
} 

void ScalarConverter::resultCasting(std::string input, std::string typeConvert, bool anyInfinity){
    try{
		if(typeConvert == "CHAR" && anyInfinity == false){
			char convertChar = static_cast<char>(input[0]);
			this->cValue = static_cast<char>(convertChar);
			this->iValue = static_cast<int>(convertChar);
			this->fValue = static_cast<float>(convertChar);
			this->dValue = static_cast<double>(convertChar);
		}
		else if(typeConvert == "INT" && anyInfinity == false)
		{
			int convertInt = std::stoi(input);
			this->cValue = static_cast<char>(convertInt);
			this->iValue = static_cast<int>(convertInt);
			this->fValue = static_cast<float>(convertInt);
			this->dValue = static_cast<double>(convertInt);
		}
		else if(typeConvert == "FLOAT" && anyInfinity == false){
			float convertFloat = std::stof(input);
			this->cValue = static_cast<char>(convertFloat);
			this->iValue = static_cast<int>(convertFloat);
			this->fValue = static_cast<float>(convertFloat);
			this->dValue = static_cast<double>(convertFloat);
		}
		else if(typeConvert == "DOUBLE" && anyInfinity == false){
			double convertDouble = std::stod(input);
			this->cValue = static_cast<char>(convertDouble);
			this->iValue = static_cast<int>(convertDouble);
			this->fValue = static_cast<float>(convertDouble);
			this->dValue = static_cast<double>(convertDouble);
		}
	}
	catch (const std::out_of_range& e){
		std::cout << typeConvert << " : <" << input << "> out of range " << std::endl;
	}
}


void ScalarConverter::convert(const std::string input){
	ScalarConverter a;
	bool anyInfinity = false;
	std::string convertType = a.getType(input);
	
	if(convertType == "infinity")
		anyInfinity = true;
	if(convertType == "empty")
		std::cout << "Error : ./convert [Empty]" << std::endl;
	else if (convertType == "Argument Error")
		std::cout << "Error : ./convert [Invalid İnput]" << std::endl;
	else if (convertType == "Out Of Range")
		std::cout << "Error : ./convert [İnput out of range.]" << std::endl;
	else {
		std::cout << "Convert Type : " << convertType << std::endl; 
		a.resultCasting(input, convertType, anyInfinity);
		a.resultPrintChar(anyInfinity);
		a.resultPrintInt(anyInfinity);
		a.resultPrintFloatDouble(input, convertType, anyInfinity);
	}
}