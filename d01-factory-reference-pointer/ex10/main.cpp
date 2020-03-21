
#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
	if (ac == 1)
	{
		std::string s;
		while (std::getline(std::cin, s)){
			std::cout << s << std::endl;
		}
	}else{
		std::string		line = "";
		int				i = 1;

		while (i < ac)
		{
			std::ifstream	ifs(av[i]);
			if (ifs.is_open())
			{
				while (getline(ifs, line))
					std::cout << line << std::endl;
			}
			else
			{
				std::cout << "cato9tails: | " << av[i] << " | " << strerror(errno) << std::endl;
			}
			ifs.close();
			i++;
		}
	}
	return (0);
}