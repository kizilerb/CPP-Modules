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
		HumanB(string name);
		void setWeapon(Weapon *WepB);
};

#endif
