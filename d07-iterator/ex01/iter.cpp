#include <iostream>
#include <iomanip>


template <typename T>
void
	putToCout
		(T &data)
{
	std::cout << data << " : ";
}

template <typename T>
void
	iter
		(T * array, size_t length, void (*func)(T &))
{
	size_t i = -1;

	while (++i < length)
		(*func)(array[i]);
}

int main( void )
{

	std::string	testStr[] = {"Apple", "Banana", "Cocos", "Donut"};
	std::cout << "Array of strings:" << std::endl;
	iter<std::string>(testStr, 4, &putToCout<std::string>);
	std::cout << std::endl;
	char	testChar[] = { 'A', 'B', 'C', 'D'};
	std::cout <<  "Array of char:" << std::endl;
	iter<char>(testChar, 4, &putToCout<char>);
	std::cout << std::endl;
	int 	testInt[] = { 1, 12, 123, 1234};
	std::cout << "Array of int:" << std::endl;
	iter<int>(testInt, 4, &putToCout<int>);
	std::cout << std::endl;
	float 	testFloat[] = { 1.11, 1.20, 1.55, 1.56};
	std::cout << std::fixed << std::setprecision(2);
	std::cout << "Array of double:" << std::endl;
	iter<float>(testFloat, 4, &putToCout<float>);








	return (0);
}