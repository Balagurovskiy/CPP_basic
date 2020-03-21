
// #include <string>
// #include <ctime>
// #include <cstdlib>
// #include <iostream>

struct Data
{
	std::string s1;
	int		 n;
	std::string s2;
};

// void	*serialize(void)
// {
// 	Data *d = new Data;
// 	char str1[9];
// 	char str2[9];

// 	srand(time(nullptr));
// 	static const char alnum[] =
// 		"0123456789"
// 		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
// 		"abcdefghijklmnopqrstuvwxyz";
// 	for (int i = 0;i < 8;i++)
// 	{
// 		str1[i] = alnum[rand() % 61];
// 		str2[i] = alnum[rand() % 61];
// 	}
// 	str1[8] = '\0';
// 	str2[8] = '\0';
// 	d->n = rand();
// 	d->s1.assign(str1);
// 	d->s2.assign(str2);
// 	std::cout << "pre s1: " << d->s1 << std::endl;
// 	std::cout << "pre  n: " << d->n  << std::endl;
// 	std::cout << "pre s2: " << d->s2 << std::endl;
// 	return (reinterpret_cast<void*>(d));
// }

// Data	*deserialize(void *raw)
// {
// 	return (reinterpret_cast<Data*>(raw));
// }

int main()
{
	void *gib;
	Data *d;

	// gib = serialize();
	// d = deserialize(gib);

	// std::cout << "s1: " << d->s1 << std::endl;
	// std::cout << " n: " << d->n << std::endl;
	// std::cout << "s2: " << d->s2 << std::endl;
	return (0);
}
