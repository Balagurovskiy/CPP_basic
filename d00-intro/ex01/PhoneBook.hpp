
#ifndef PHONEBOOK_H
# define PHONEBOOK_H


#include "Libs.hpp"
#include "Contact.hpp"

class	PhoneBook {

	public: 

		PhoneBook(void); 
		~PhoneBook(void);

		void				add_contact(Contact contact);
		void				print_contact_info(int id);
		void		 		display_contacts(void);
		int					is_empty(void);	

	private:
		int const static	_contacts_max = 8;
		int					_contacts_in_book;
		Contact 			_contacts[8];

		std::string 		foramat_contact(std::string str);
		void				add_print(void);
}; 

#endif