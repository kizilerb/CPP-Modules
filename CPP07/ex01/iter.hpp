#include <iostream>

template<typename A>
void screenPrint(A& value, int i){
	std::cout << "Array[" << i << "]: " << value << std::endl;
}

template<typename A>
void iter(A *array, int lenght, void (*func)(A&, int)){
	for(int i = 0; i < lenght ; i++)
		func(array[i], i);
}