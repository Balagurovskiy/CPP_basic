NAME	= array

SRC		= main.cpp

FLAGS	= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	clang++ $(FLAGSs) $(SRC) -I . -o $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all