
#include "Libs.hpp"
#include "Contact.hpp"
#include "PhoneBook.hpp"

void		add_contacts(PhoneBook *phoneBook){
	
	Contact 		contact;
	std::string 	response = "";
	int 			set_success = 1;

	while(set_success){
		std::cout << contact.ask_first_name();
		std::getline(std::cin, response);
		set_success = contact.set_first_name(response);
		std::cout << std::endl;
	}
	set_success = 1;
	while(set_success){
		std::cout << contact.ask_last_name();
		std::getline(std::cin, response);
		set_success = contact.set_last_name(response);
		std::cout << std::endl;
	}
	set_success = 1;
	while(set_success){
		std::cout << contact.ask_nickname();
		std::getline(std::cin, response);
		set_success = contact.set_nickname(response);
		std::cout << std::endl;
	}
	set_success = 1;
	while(set_success){
		std::cout << contact.ask_login();
		std::getline(std::cin, response);
		set_success = contact.set_login(response);
		std::cout << std::endl;
	}
	set_success = 1;
	while(set_success){
		std::cout << contact.ask_postal_address();
		std::getline(std::cin, response);
		set_success = contact.set_postal_address(response);
		std::cout << std::endl;
	}
	set_success = 1;
	while(set_success){
		std::cout << contact.ask_email_address();
		std::getline(std::cin, response);
		set_success = contact.set_email_address(response);
		std::cout << std::endl;
	}
	set_success = 1;
	while(set_success){
		std::cout << contact.ask_phone_number();
		std::getline(std::cin, response);
		set_success = contact.set_phone_number(response);
		std::cout << std::endl;
	}
	set_success = 1;
	while(set_success){
		std::cout << contact.ask_birthday_date();
		std::getline(std::cin, response);
		set_success = contact.set_birthday_date(response);
		std::cout << std::endl;
	}
	set_success = 1;
	while(set_success){
		std::cout << contact.ask_favorite_meal();
		std::getline(std::cin, response);
		set_success = contact.set_favorite_meal(response);
		std::cout << std::endl;
	}
	set_success = 1;
	while(set_success){
		std::cout << contact.ask_underwear_color();
		std::getline(std::cin, response);
		set_success = contact.set_underwear_color(response);
		std::cout << std::endl;
	}
	set_success = 1;
	while(set_success){
		std::cout << contact.ask_darkest_secret();
		std::getline(std::cin, response);
		set_success = contact.set_darkest_secret(response);
		std::cout << std::endl;
	}

	phoneBook->add_contact(contact);
}

void		request_contacts(PhoneBook *phoneBook){
	std::string response_id = "";
	int 		contact_id = -1;

	std::cout << "Enter contact index for more details." << std::endl;
	std::cout << "=> ";
	std::getline(std::cin, response_id);
	if (response_id.compare("0") == 0)
		contact_id = 0;
	else if (response_id.compare("1") == 0)
		contact_id = 1;
	else if (response_id.compare("2") == 0)
		contact_id = 2;
	else if (response_id.compare("3") == 0)
		contact_id = 3;
	else if (response_id.compare("4") == 0)
		contact_id = 4;
	else if (response_id.compare("5") == 0)
		contact_id = 5;
	else if (response_id.compare("6") == 0)
		contact_id = 6;
	else if (response_id.compare("7") == 0)
		contact_id = 7;
	else{
		std::cout << "\nSorry, that index number is invalid.\n" << std::endl;
		return ;
	}
	phoneBook->print_contact_info(contact_id);
}

void		search_contacts(PhoneBook *phoneBook){

	if (phoneBook->is_empty())
	{
		std::cout << "\nPhoneBook is empty!\n" << std::endl;
		return ;
	}
	phoneBook->display_contacts();
	request_contacts(phoneBook);
}

void	request_listener(std::string request, PhoneBook *phoneBook){
	if (request.compare("EXIT") == 0)
		exit(0) ;
	else if (request.compare("ADD") == 0)
		add_contacts(phoneBook);
	else if (request.compare("SEARCH") == 0)
		search_contacts(phoneBook);

}

int		main(void)
{
	PhoneBook phoneBook;
	std::string request = " ";

	std::cout << "\n   Welcome to crappy phonebook!" << std::endl;
	while (1)
	{
		std::cout << "\n   <ADD>   <SEARCH>   <EXIT>\n" << std::endl;
		std::cout << "=> ";
		std::getline(std::cin, request);
		if (std::cin.eof())
		{
			std::cout << "CTRL + D pressed, bye." << std::endl;
			return (0);
		}
		request_listener(request, &phoneBook);
	}
	return (0);
}