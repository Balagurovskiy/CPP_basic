NAME = phonebook

COMPILER = clang++

FLAGS = -Wall -Werror -Wextra

SOURCE = main.cpp Contact.cpp PhoneBook.cpp

OBJECT = $(SOURCE:.cpp=.o)

all:
	@$(COMPILER) $(FLAGS) -c $(SOURCE)
	@$(COMPILER) $(OBJECT) -I . -o $(NAME)

clean:
	@rm -rf $(OBJECT)

fclean: 
	@make clean
	@rm -rf $(NAME)

re:
	@make fclean
	@make all