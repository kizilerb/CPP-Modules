#include "Serialization.hpp"

int main ()
{
	Data		data1;
	Data*		data2;
	uintptr_t	s_ptr1;
	uintptr_t	s_ptr2;

	data1.color = "Blue";
	data1.price = 10000;

	std::cout << "Data1: " << data1.color << ", " << data1.price << std::endl;
	std::cout << "data1 address: " << &data1 << std::endl;
	s_ptr1 = Serializer::serialize(&data1);
	std::cout << "data1 address: " << s_ptr1 << std::endl;
	std::cout << std::endl;
	
	data2 = Serializer::deserialize(s_ptr1);

	std::cout << "Data2: " << data2->color << ", " << data2->price << std::endl;
	std::cout << "data2 address: " << data2 << std::endl;
	s_ptr2 = Serializer::serialize(data2);
	std::cout << "data2 address: " << s_ptr2 << std::endl;
	std::cout << std::endl;

	if (data2 == &data1)
		std::cout << "Data's addresses are the same" << std::endl;
}