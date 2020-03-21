

#include "Contact.hpp"

Contact::Contact(void) 
{
	this->_first_name = "* empty *";
	this->_last_name = "* empty *";
	this->_nickname = "* empty *";
	this->_login = "* empty *";
	this->_postal_address = "* empty *";
	this->_email_address = "* empty *";
	this->_phone_number = "* empty *";
	this->_birthday_date =  "* empty *";
	this->_favorite_meal = "* empty *";
	this->_underwear_color = "* empty *";
	this->_darkest_secret = "* empty *";
	return;
}

Contact::~Contact(void) 
{
	return;
}

int		Contact::set_first_name(std::string str){
	if (str.empty())
		return (1);
	this->_first_name = str;
	return (0);

}
int		Contact::set_last_name(std::string str){
	if (str.empty())
		return (1);
	this->_last_name = str;
	return (0);
}
int		Contact::set_nickname(std::string str){
	if (str.empty())
		return (1);
	this->_nickname = str;
	return (0);
}
int		Contact::set_login(std::string str){
	if (str.empty())
		return (1);
	this->_login = str;
	return (0);
}
int		Contact::set_postal_address(std::string str){
	if (str.empty())
		return (1);
	this->_postal_address = str;
	return (0);
}
int		Contact::set_email_address(std::string str){
	if (str.empty())
		return (1);
	this->_email_address = str;
	return (0);
}
int		Contact::set_phone_number(std::string str){
	if (str.empty())
		return (1);
	this->_phone_number = str;
	return (0);
}
int		Contact::set_birthday_date(std::string str){
	if (str.empty())
		return (1);
	this->_birthday_date = str;
	return (0);
}
int		Contact::set_favorite_meal(std::string str){
	if (str.empty())
		return (1);
	this->_favorite_meal = str;
	return (0);
}
int		Contact::set_underwear_color(std::string str){
	if (str.empty())
		return (1);
	this->_underwear_color = str;
	return (0);
}
int		Contact::set_darkest_secret(std::string str){
	if (str.empty())
		return (1);
	this->_darkest_secret = str;
	return (0);
}

std::string	Contact::get_first_name(void){
	return (this->_first_name);
}
std::string	Contact::print_first_name(void){
	return ("First Name : " + this->_first_name);
}
std::string	Contact::ask_first_name(void){
	return ("Set a First Name ...");
}

std::string	Contact::get_last_name(void){
	return (this->_last_name);
}
std::string	Contact::print_last_name(void){
	return ("Last Name : " + this->_last_name);
}
std::string	Contact::ask_last_name(void){
	return ("Set a Last Name ...");
}

std::string	Contact::get_nickname(void){
	return (this->_nickname);
}
std::string	Contact::print_nickname(void){
	return ("Nickname : " + this->_nickname);
}
std::string	Contact::ask_nickname(void){
	return ("Set a Nickname ...");
}

std::string	Contact::get_login(void){
	return (this->_login);
}
std::string	Contact::print_login(void){
	return ("Login : " + this->_login);
}
std::string	Contact::ask_login(void){
	return ("Set a Login ...");
}

std::string	Contact::get_postal_address(void){
	return (this->_postal_address);
}
std::string	Contact::print_postal_address(void){
	return ("Postal Address : " + this->_postal_address);
}
std::string	Contact::ask_postal_address(void){
	return ("Set a Postal Address ...");
}

std::string	Contact::get_email_address(void){
	return (this->_email_address);
}
std::string	Contact::print_email_address(void){
	return ("Email Address : " + this->_email_address);
}
std::string	Contact::ask_email_address(void){
	return ("Set a Email Address ...");
}

std::string	Contact::get_phone_number(void){
	return (this->_phone_number);
}
std::string	Contact::print_phone_number(void){
	return ("Phone Number : " + this->_phone_number);
}
std::string	Contact::ask_phone_number(void){
	return ("Set a Phone Number ...");
}

std::string	Contact::get_birthday_date(void){
	return (this->_birthday_date);
}
std::string	Contact::print_birthday_date(void){
	return ("Birthday Date : " + this->_birthday_date);
}
std::string	Contact::ask_birthday_date(void){
	return ("Set a Birthday Date ...");
}

std::string	Contact::get_favorite_meal(void){
	return (this->_favorite_meal);
}
std::string	Contact::print_favorite_meal(void){
	return ("Favorite Meal : " + this->_favorite_meal);
}
std::string	Contact::ask_favorite_meal(void){
	return ("Set a Favorite Meal ...");
}

std::string	Contact::get_underwear_color(void){
	return (this->_underwear_color);
}
std::string	Contact::print_underwear_color(void){
	return ("Underwear Color : " + this->_underwear_color);
}
std::string	Contact::ask_underwear_color(void){
	return ("Set a Underwear Color ...");
}

std::string	Contact::get_darkest_secret(void){
	return (this->_darkest_secret);
}
std::string	Contact::print_darkest_secret(void){
	return ("Darkest Secret : " + this->_darkest_secret);
}
std::string	Contact::ask_darkest_secret(void){
	return ("Set a Darkest Secret ...");
}
