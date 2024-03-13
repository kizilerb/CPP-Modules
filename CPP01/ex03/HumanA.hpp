#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanA{
	private :
		Weapon &WepA;
		string name;
	public :
		HumanA(string human, Weapon& Weapon);
		void attack();
};

#endif
