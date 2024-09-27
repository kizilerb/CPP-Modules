#include "iter.hpp"

int main(){
	int a[] = {123,23,323,234,565};
	int size = sizeof(a) / sizeof(a[0]);
	::iter(a, size, screenPrint<int>);
}