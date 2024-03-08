#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP


# include "Contact.hpp"

class Phonebook {
	private :
		Contact ContactList[8];

	public :
		void PrintTable();
		void ADD();
		void SEARCH();
};

#endif
