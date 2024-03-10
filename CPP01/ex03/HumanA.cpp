#include "HumanA.hpp"

HumanA::HumanA(string name, Weapon* WepA){
	this->name = name;
	this->WepA = WepA;
	cout << "Constructor for HumanA class is called, weapon and name is set." << endl;
}

void HumanA::attack(){
	cout << this->name << " attacks with their " << this->WepA->getType() << endl;
}
