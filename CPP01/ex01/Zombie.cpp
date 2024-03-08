#include "zombie.hpp"

void Zombie::setName(string name){
	this->name = name;
}

string Zombie::getName(){
	return this->name;
}

void Zombie::announce(){
	cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << endl;
}

Zombie::~Zombie(){
	cout << "Destructor is called for: " << this->name << endl;
}
