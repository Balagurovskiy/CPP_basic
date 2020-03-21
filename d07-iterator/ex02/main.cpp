
#include "Array.hpp"
#include <iomanip>

void success(){
	std::cout << "\n - - - - - SUCCESS - - - - - " << std::endl;
	try
	{
		Array<char> charArray(10);
		std::cout << " char array [" << charArray.size() << "]:" << std::endl;
		int i = -1;
		int size = charArray.size();
		while(++i < size)
			charArray[i] = static_cast<char>(66 + rand() % 34);
		i = -1;
		while(++i < size)
			std::cout << "[" << i << "] "<< charArray[i] << ";  ";
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
void signed_size(){
	std::cout << "\n - - - - - SIGNED SIZE - - - - - " << std::endl;
	try
	{
		unsigned int size = -5;
		Array<int> intArray(size);

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
void init_out_of_bounds(){
	std::cout << "\n - - - - - INIT OUT OF BOUNDS - - - - - " << std::endl;
	try
	{
		unsigned int size = 5;
		Array<int> intArray(size);

		int i = -1;
		while(++i < size + 1)
			intArray[i] = rand() % 10;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
void call_out_of_bounds(){
	std::cout << "\n - - - - - CALL OUT OF BOUNDS - - - - - " << std::endl;
	try
	{
		Array<int> intArray(5);

		int i = -1;
		int size = intArray.size();
		while(++i < size)
			intArray[i] = rand() % 10;
		i = -1;
		while(++i < size + 1)
			std::cout << "[" << i << "] "<< intArray[i] << ";  ";
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void copy(){
	std::cout << "\n - - - - - COPY - - - - - " << std::endl;
	try
	{
		Array<int> intArray(5);
		std::cout << "*1* int array [" << intArray.size() << "]:" << std::endl;
		int i = -1;
		int size = intArray.size();
		while(++i < size)
			intArray[i] = rand() % 34;
		i = -1;
		while(++i < size)
			std::cout << "[" << i << "] "<< intArray[i] << ";  ";
		std::cout << std::endl;

		std::cout << "" << std::endl;

		Array<int> intArray2(10);
		std::cout << "*2* int array [" << intArray2.size() << "]:" << std::endl;
		i = -1;
		size = intArray2.size();
		while(++i < size)
			intArray2[i] = 66 + rand() % 34;
		i = -1;
		while(++i < size)
			std::cout << "[" << i << "] "<< intArray2[i] << ";  ";
		std::cout << std::endl;

		std::cout << "" << std::endl;
		std::cout << "*1* = *2*" << std::endl;
		intArray = intArray2;
		std::cout << "" << std::endl;

		std::cout << "*1* int array [" << intArray.size() << "]:" << std::endl;
		i = -1;
		size = intArray.size();
		while(++i < size)
			std::cout << "[" << i << "] "<< intArray[i] << ";  ";
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
int main(void)
{
	srand(time(0));
	success();
	init_out_of_bounds();
	call_out_of_bounds();
	signed_size();
	copy();
	return (0);
}

