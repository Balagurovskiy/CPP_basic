#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>

struct Data
{
	std::string s1;
	std::string s2;
	int		 n;
};

void	*serialize(void)
{
	Data *data = new Data;
	char s1[9];
	char s2[9];

	srand(time(0));
	static const char alphanumerical[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	for (int i = 0;i < 8;i++)
	{
		s1[i] = alphanumerical[rand() % 61];
		s2[i] = alphanumerical[rand() % 61];
	}
	s1[8] = '\0';
	s2[8] = '\0';
	data->s1.assign(s1);
	data->s2.assign(s2);
	data->n = rand();
	std::cout << "-> s1: " << data->s1 << std::endl;
	std::cout << "->  n: " << data->n  << std::endl;
	std::cout << "-> s2: " << data->s2 << std::endl;
	return (reinterpret_cast<void*>(data));
}

Data	*deserialize(void *raw)
{
	return (reinterpret_cast<Data*>(raw));
}

int main()
{
	void * ser = serialize();
	std::cout << "serialize => " << ser << " => deserialize "<<std::endl;
	Data * data = deserialize(ser);

	std::cout << "s1: " << data->s1 << std::endl;
	std::cout << " n: " << data->n << std::endl;
	std::cout << "s2: " << data->s2 << std::endl;
	return (0);
}