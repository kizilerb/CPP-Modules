#include <iostream>
#include <stack>

void startRPN(std::string input);
void execNumbers(int &value1, int &value2, std::stack<int> &list);
void calculate(const int &value1, const int &value2, const char &process,std::stack<int> &list);
