#include "zombie.hpp"

void bluh(){
	Zombie* men= newZombie("men");
	men->announce();
	delete men;

}

int main(){
	randomChump("bernaa");
	bluh();
}
