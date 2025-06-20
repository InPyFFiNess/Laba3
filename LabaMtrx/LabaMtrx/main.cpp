#include <iostream>
#include "Header.h"
#include <random>

int main()
{
	int32_t choiseInput{};
	int32_t line{};
	int32_t column{};
	std::cout << "Input number of strings: ";
	std::cin >> line;
	std::cout << "Input number of columns: ";
	std::cin >> column;
	std::cout << "Random Input or Handle Input: " << '\n' << "Random - 1" << "\n" << "Handle - 2" << '\n';
	std::cin >> choiseInput;
	int32_t** mtrx = nullptr;
	DataForMtrx(mtrx, line, column);
	int32_t** copyMtrx = nullptr;
	DataForMtrx(copyMtrx, line, column);
	if (choiseInput == 1)
	{
		RandomMtrx(mtrx, line, column);
		CopyMtrx(mtrx, copyMtrx, line, column);
		std::cout << "Your Matrix:" << '\n';
		PrintMtrx(mtrx, line, column);
	}
	else if (choiseInput == 2)
	{
		InputMtrx(mtrx, line, column);
		CopyMtrx(mtrx, copyMtrx, line, column);
	}
	else
	{
		std::cout << "Wrong Choise!";
		return 0;
	}
	OutputMultiStirng(copyMtrx,line,column);
	SwithMtrxForMax(mtrx, line, column);
	DeleteData(mtrx, line);
	DeleteData(copyMtrx, line);
	return 0;
}