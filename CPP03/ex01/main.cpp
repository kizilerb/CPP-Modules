#include "ScavTrap.hpp"

int main(){
	ScavTrap a("Ally");
	ScavTrap b("Bell");

	a.attack("Ally");
	b.takeDamage(a.getADamage());
	a.guardGate();
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
	b.attack("Bell");
	std::cout << "Ally Hit points: " << a.getHPoints() << " Ally energy points: "<< a.getEPoints() << std::endl;
	std::cout << "Bell Hit points: " << b.getHPoints() << " Bell energy points: "<< b.getEPoints() << std::endl;
	a.takeDamage(b.getADamage());
	a.beRepaired(15);
	return 0;
}
