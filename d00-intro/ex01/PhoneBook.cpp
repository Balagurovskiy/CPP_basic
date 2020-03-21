#include "Contact.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) 
{
	this->_contacts_in_book = 0;
	return;
}

PhoneBook::~PhoneBook(void) 
{
	return;
}

void		PhoneBook::add_print(void){
	std::cout << std::endl;
	std::cout << "Contact";
	std::cout << " [" << this->_contacts_in_book << "/" << _contacts_max << "] ";
	std::cout << "added : "<<std::endl;
	std::cout << this->_contacts[_contacts_in_book].print_first_name() << std::endl;
	std::cout << this->_contacts[_contacts_in_book].print_last_name() << std::endl;
	std::cout << std::endl;
}

void		PhoneBook::add_contact(Contact contact){
	if (this->_contacts_in_book >= _contacts_max){
		std::cout << "You achived the maximum number of contacts!" <<std::endl;
		return ;
	}
	this->_contacts[_contacts_in_book] = contact;
	this->add_print();
	this->_contacts_in_book++;	
}

std::string PhoneBook::foramat_contact(std::string str)
{
	int 		length = 0;
	int 		spaces = 0;
	std::string spaces_temp;

	length = str.length();
	if(length < 10){
		spaces = 10 - length;
		while(spaces--)
			spaces_temp += " ";
		str = spaces_temp + str;
	}
	if(length > 10){
		str.replace(9, length, ".");
	}
	return (str);
}

void		PhoneBook::display_contacts(void){
	int 		i = 0;

	std::cout <<  std::endl;
	std::cout << " ___________________________________________ " << std::endl;
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|" << std::endl;
	std::cout << " =========================================== " << std::endl;
	while(i < this->_contacts_in_book){
		std::cout << "|         " << i;
		std::cout << "|" << this->foramat_contact(this->_contacts[i].get_first_name());
		std::cout << "|" << this->foramat_contact(this->_contacts[i].get_last_name());
		std::cout << "|" << this->foramat_contact(this->_contacts[i].get_nickname());
		std::cout << "|" << std::endl;
		i++;
	}
	std::cout << " ------------------------------------------- " << std::endl;
}

void		PhoneBook::print_contact_info(int contact_id){
	if (contact_id >= this->_contacts_in_book || contact_id < 0)
	{
		std::cout << "\nThere is no contact with this index!\n" << std::endl;
		return ;
	}
	std::cout << std::endl;
	std::cout << this->_contacts[contact_id].print_first_name() << std::endl;
	std::cout << this->_contacts[contact_id].print_last_name() << std::endl;
	std::cout << this->_contacts[contact_id].print_nickname() << std::endl;
	std::cout << this->_contacts[contact_id].print_login() << std::endl;
	std::cout << this->_contacts[contact_id].print_postal_address() << std::endl;
	std::cout << this->_contacts[contact_id].print_email_address() << std::endl;
	std::cout << this->_contacts[contact_id].print_phone_number() << std::endl;
	std::cout << this->_contacts[contact_id].print_birthday_date() << std::endl;
	std::cout << this->_contacts[contact_id].print_favorite_meal() << std::endl;
	std::cout << this->_contacts[contact_id].print_underwear_color() << std::endl;
	std::cout << this->_contacts[contact_id].print_darkest_secret() << std::endl;
	std::cout << std::endl;
}

int		PhoneBook::is_empty(void){
	return (this->_contacts_in_book == 0);
}