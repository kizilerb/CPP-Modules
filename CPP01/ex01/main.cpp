#include "zombie.hpp"

void produce(){
	Zombie *bluh = zombieHorde(7, "alp");
	for (int i = 0; i < 7; i++)
		bluh[i].announce();
	delete[] bluh;
}

int main(){
	produce();
}
