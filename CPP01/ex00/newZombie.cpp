#include "zombie.hpp"

Zombie* newZombie(string name){
	Zombie* cat = new Zombie;
	cat->setName(name);
	return cat;
}
