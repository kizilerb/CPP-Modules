#include "ScavTrap.hpp"

int main(){
	ScavTrap a("Ally");
	ScavTrap b("Bell");

	a.attack("Ally");
	b.takeDamage(a.getADamage());
	b.beRepaired(10);
	b.attack("Bell");
	a.takeDamage(b.getADamage());
	b.attack("Bell");
	a.takeDamage(b.getADamage());
	b.attack("Bell");
	a.takeDamage(b.getADamage());
	b.attack("Bell");
	a.takeDamage(b.getADamage());
	b.attack("Bell");
	a.takeDamage(b.getADamage());
	b.beRepaired(15);
	return 0;
}
