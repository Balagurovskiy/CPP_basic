
NAME	= conversion

SRC		= main.cpp

CFLAG	= -Wconversion -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	clang++ $(CFLAG) $(SRC) -I . -o $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all