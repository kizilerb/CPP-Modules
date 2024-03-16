#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
	this->name = "";
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDmg = 20;
	std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name){
	this->name = name;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDmg = 20;
	std::cout << "ScavTrap Constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& copy){
	*this = copy;
	std::cout << "ScavTrap Copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other){
	std::cout << "Scavtrap Copy assignment operator called" << std::endl;
	this->attackDmg = other.attackDmg;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	return *this;
}

void ScavTrap::attack(const std::string& target){
    if(this->hitPoints > 0 && this->energyPoints > 0)
    {
        std::cout << "ScavTrap "<< this->name << " attacks " << target << ", causing "<< this->attackDmg << " points of damage!" << std::endl;
        this->energyPoints--;
    }
    else if (this->energyPoints == 0)
        std::cout << "Low Energy. Cannot attack." << std::endl;
    else
        std::cout << "ScavTrap is dead." << std::endl;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap is now in Gate keeper mode." << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap Destructor called." << std::endl;
}
