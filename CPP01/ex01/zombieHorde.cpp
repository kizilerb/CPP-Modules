#include "zombie.hpp"

Zombie* zombieHorde( int N, string name ){
	Zombie *herd = new Zombie[N];
	for (int i = 0; i < N; i++)
		herd[i].setName(name);
	return herd;
}
