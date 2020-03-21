
#include <iostream>

int		is_low_char(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

char	to_capital(char c)
{
	if (is_low_char(c))
		return (c - 32);
	return (c);
}

void	out_args_to_capital(char **av)
{
	int	strings;
	int	chars;

	strings = 1;
	while (av[strings])
	{
		chars = 0;
		while(av[strings][chars])
		{
			std::cout << to_capital(av[strings][chars]);
			chars++;
		}
		strings++;
	}
}

int		main(int ac, char	**av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
		out_args_to_capital(av);
	std::cout << std::endl;
	return (0);
}