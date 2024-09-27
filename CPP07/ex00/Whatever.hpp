#include <iostream>

template <typename A>
A min(A x, A y){
	return (x < y) ? x : y;
}

template <typename A>
A max(A x, A y){
	return (x > y) ? x : y;
}

template <typename A>
void swap(A &x, A &y){
	A temp = x;
	x = y;
	y = temp;
}