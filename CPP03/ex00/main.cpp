#include "ClapTrap.hpp"

int main(){
	ClapTrap a("Anna");
	ClapTrap b("Benny");

	a.attack("Benny");
	b.takeDamage(a.getADamage());
	b.beRepaired(5);
	b.attack("Anna");
	a.takeDamage(b.getADamage());
	b.beRepaired(15);
	return 0;
}
