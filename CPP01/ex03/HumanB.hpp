#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"


class HumanB {
	private :
		Weapon *WepB;
		string name;
	public :
		void attack();
		HumanB(string human);
		void setWeapon(Weapon &Weapon);
};

#endif
