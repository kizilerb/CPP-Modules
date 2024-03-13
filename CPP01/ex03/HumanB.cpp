#include "HumanB.hpp"

HumanB::HumanB(string human){
	this->name = human;
	cout << "Constructer is called for HumanB class and name is set." << endl;
}

void HumanB::attack(){
	cout << this->name << " attacks with their "<< this->WepB->getType() << endl;
}

void HumanB::setWeapon(Weapon &Weapon)
{
	this->WepB = &Weapon;
	return;
}
