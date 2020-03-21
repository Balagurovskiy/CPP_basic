
#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
// #include <string>

class	Contact {

	public: 

		Contact(void); 
		~Contact(void);

		int		set_first_name(std::string);
		int		set_last_name(std::string);
		int		set_nickname(std::string);
		int		set_login(std::string);
		int		set_postal_address(std::string);
		int		set_email_address(std::string);
		int		set_phone_number(std::string);
		int		set_birthday_date(std::string);
		int		set_favorite_meal(std::string);
		int		set_underwear_color(std::string);
		int		set_darkest_secret(std::string);

		std::string	get_first_name(void);
		std::string	print_first_name(void);
		std::string	ask_first_name(void);

		std::string	get_last_name(void);
		std::string	print_last_name(void);
		std::string	ask_last_name(void);

		std::string	get_nickname(void);
		std::string	print_nickname(void);
		std::string	ask_nickname(void);

		std::string	get_login(void);
		std::string	print_login(void);
		std::string	ask_login(void);

		std::string	get_postal_address(void);
		std::string	print_postal_address(void);
		std::string	ask_postal_address(void);

		std::string	get_email_address(void);
		std::string	print_email_address(void);
		std::string	ask_email_address(void);

		std::string	get_phone_number(void);
		std::string	print_phone_number(void);
		std::string	ask_phone_number(void);

		std::string	get_birthday_date(void);
		std::string	print_birthday_date(void);
		std::string	ask_birthday_date(void);

		std::string	get_favorite_meal(void);
		std::string	print_favorite_meal(void);
		std::string	ask_favorite_meal(void);

		std::string	get_underwear_color(void);
		std::string	print_underwear_color(void);
		std::string	ask_underwear_color(void);

		std::string	get_darkest_secret(void);
		std::string	print_darkest_secret(void);
		std::string	ask_darkest_secret(void);

	private:
		std::string _first_name;
		std::string _last_name;
		std::string _nickname;
		std::string _login;
		std::string _postal_address;
		std::string _email_address;
		std::string _phone_number;
		std::string _birthday_date;
		std::string _favorite_meal;
		std::string _underwear_color;
		std::string _darkest_secret;

}; 

#endif