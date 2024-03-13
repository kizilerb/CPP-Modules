#include "HumanA.hpp"

HumanA::HumanA(string human, Weapon& Weapon) : WepA(Weapon) , name(human)
{
	cout << "Constructor for HumanA class is called, weapon and name is set." << endl;
}

void HumanA::attack(){
	cout << this->name << " attacks with their " << this->WepA.getType() << endl;
}
