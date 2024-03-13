#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Weapon{
	private :
		string type;
	public :
		Weapon(string type);
		const string& getType() const;
		void setType(string type);
};

#endif
