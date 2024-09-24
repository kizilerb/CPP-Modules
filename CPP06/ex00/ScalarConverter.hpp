#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>

class ScalarConverter{
	private:
		char cValue;
		int iValue;
		float fValue;
		double dValue;

		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& copy);
		~ScalarConverter();

		std::string getType(const std::string input);
		static bool anyLetter(std::string input, std::string type);
		void resultCasting(std::string input, std::string typeConvert, bool anyInfinity);

		void resultPrintChar(bool anyInfinity);
		void resultPrintInt(bool anyInfinity);
		void resultPrintFloatDouble(std::string input, std::string type, bool anyInfinity);

		class InvalidArgument : public std::exception {
		public:
			virtual const char* what() const throw();
		};

		public:
		static void convert(const std::string input);
};


#endif
