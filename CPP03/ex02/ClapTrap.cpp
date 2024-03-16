#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
	this->name = "";
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDmg = 0;
	std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name){
	this->name = name;
	this->hitPoints = 10;
	this->energyPoints = 10;
	this->attackDmg = 0;
	std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& copy){
	*this = copy;
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
	std::cout << "Copy assignment operator called" << std::endl;
	this->attackDmg = other.attackDmg;
	this->hitPoints = other.hitPoints;
	this->energyPoints = other.energyPoints;
	return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target){
	if(this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "ClapTrap "<< this->name << " attacks " << target << ", causing "<< this->attackDmg << " points of damage!" << std::endl;
		this->energyPoints--;
	}
	else if (this->energyPoints == 0)
		std::cout << "Low Energy. Cannot attack." << std::endl;
	else
		std::cout << "ClapTrap is dead. Cannot attack." << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
	if(this->hitPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " taking damage (" << amount << ") " << std::endl;
		this->hitPoints -= amount;
	}
	else
		std::cout << "ClapTrap is dead. Cannot take damage." << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	if(this->hitPoints > 0 && this->energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->name << " repairing itself (+" << amount << ") "  << "(!This will cause energy points!)" << std::endl;
		this->energyPoints--;
		this->hitPoints += amount;
		std::cout << "New Hit Points -> " << this->hitPoints << std::endl;
	}
	else if (this->energyPoints == 0)
		std::cout << "Low Energy. Cannot get reapired." << std::endl;
	else
		std::cout << "ClapTrap is dead. Cannot get reapired." << std::endl;
}

int ClapTrap::getHPoints(){
	return this->hitPoints;
}

int ClapTrap::getEPoints(){
	return this->energyPoints;
}

int ClapTrap::getADamage()
{
	return this->attackDmg;
}
