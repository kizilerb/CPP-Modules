#include "FragTrap.hpp"

FragTrap::FragTrap(){
	this->name = "";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDmg = 30;
	std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name){
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDmg = 20;
	std::cout << "FragTrap Constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& copy){
	*this = copy;
	std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other){
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
	this->attackDmg = other.attackDmg;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	return *this;
}

void FragTrap::attack(const std::string& target){
	if(this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "FragTrap "<< this->name << " attacks " << target << ", causing "<< this->attackDmg << " points of damage!" << std::endl;
		this->energyPoints--;
	}
	else if (this->energyPoints == 0)
		std::cout << "Low Energy. Cannot attack." << std::endl;
	else
		std::cout << "FragTrap is dead." << std::endl;
}

void FragTrap::highFivesGuys(){
	std::cout << "Hey guys how about a high five? 👋🏻" << std::endl;
}


FragTrap::~FragTrap(){
	std::cout << "FragTrap Destructor called." << std::endl;
}
