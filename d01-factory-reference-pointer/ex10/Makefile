NAME = cato9tails

COMPILER = clang++

FLAGS = -Wall -Werror -Wextra

SOURCE = main.cpp

OBJECT = $(SOURCE:.cpp=.o)

all:
	@$(COMPILER) $(FLAGS) -c $(SOURCE)
	@$(COMPILER) $(OBJECT) -o $(NAME)

clean:
	@rm -rf $(OBJECT)

fclean: 
	@make clean
	@rm -rf *.replace
	@rm -rf $(NAME)

re:
	@make fclean
	@make all