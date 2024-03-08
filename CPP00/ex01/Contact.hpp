#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <iomanip>

class Contact {
	private :
		std::string FirstName;
		std::string LastName;
		std::string PhoneNumber;
		std::string DarkestSecret;
		std::string NickName;

	public :
		std::string GetContact(std::string input) const;
		void SetFirstName(std::string input);
		void SetLastName(std::string input);
		void SetPhoneNumber(std::string input);
		void SetDarkestSecret(std::string input);
		void SetNickName(std::string input);

};

#endif
