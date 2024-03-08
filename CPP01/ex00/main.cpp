#include "zombie.hpp"

void bluh(){
	Zombie* men= newZombie("men");
	men->announce();
	delete men;

}

int main(){
	Zombie asdas;
	asdas.setName("Sina");
	asdas.announce();
	bluh();
	randomChump("bernaa");
	randomChump("denemeee");
	system("leaks BraiiiiiiinnnzzzZ");
}
