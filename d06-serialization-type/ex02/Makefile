NAME	= identify_real_type

SRC		= main.cpp A.cpp B.cpp C.cpp Base.cpp 

CFLAG	= -Wall -Wextra -Werror

.SILENT:

all: $(NAME)

$(NAME):
	clang++ $(CFLAG) $(SRC) -I . -o $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all