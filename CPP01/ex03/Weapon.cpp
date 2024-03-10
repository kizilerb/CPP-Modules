#include "Weapon.hpp"

Weapon::Weapon(string type){
	this->type = type;
	cout << "Constructor for Weapon class is called and type is set." << endl;
}

const string& Weapon::getType(){
	return this->type;
}

void Weapon::setType(string type){
	this->type = type;
	return ;
}
