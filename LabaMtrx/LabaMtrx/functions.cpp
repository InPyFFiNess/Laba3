#include <iostream>
#include "Header.h"
#include <algorithm>
#include <random>

void DataForMtrx(int32_t**& mtrx, int32_t line, int32_t column)
{
	mtrx = new int32_t * [line];
	for (size_t i = 0; i < line; ++i)
	{
		mtrx[i] = new int32_t[column];
	}
}
void RandomMtrx(int32_t** mtrx, int32_t line, int32_t column)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int32_t> dist(-100, 100);
	for (size_t i = 0; i < line; ++i)
	{
		for (size_t j = 0; j < column; ++j)
		{
			mtrx[i][j] = dist(gen);
		}
	}
	
}

void InputMtrx(int32_t** mtrx, int32_t line, int32_t column)
{
	std::cout << "Input Matrix: " << '\n';
	for (size_t i = 0; i < line; ++i)
	{
		for (size_t j = 0; j < column; ++j)
		{
			std::cin >> mtrx[i][j];
		}
	}
}

void PrintMtrx(int32_t** mtrx, int32_t line, int32_t column)
{
	for (size_t i = 0; i < line; ++i)
	{
		for (size_t j = 0; j < column; ++j)
		{
			std::cout << mtrx[i][j] << " ";
			if (j == column-1)
			{
				std::cout << '\n';
			}
		}
	}
}

int32_t MuiliPosStrings(int32_t** mtrx, int32_t line, int32_t column, size_t i)
{
	int32_t multi{ 1 };
	for (size_t j = 0; j < column; j++)
	{
		while (j != column)
		{
			if (mtrx[i][j] < 0)
			{
				mtrx[i][j] = 0;
				multi *= mtrx[i][j];
			}
			else
			{
				multi *= mtrx[i][j];
			}
			break;
		}
	}
	return multi;
}

void OutputMultiStirng(int32_t** mtrx, int32_t line, int32_t column)
{
	for (size_t i = 0; i < line; ++i)
	{
		if (MuiliPosStrings(mtrx, line, column, i) == 0)
		{
			std::cout << "String number " << i + 1 << " have negative elements\n";
		}
		else
		{
			std::cout << "Multiplication of " << i + 1 << " string = " << MuiliPosStrings(mtrx, line, column, i) << '\n';
		}
	}
}

int32_t MaxStringIndex(int32_t** mtrx, int32_t line, int32_t column)
{
	int32_t maxElement{mtrx[0][0]};
	int32_t maxStringIndex{};
	for (size_t i = 0; i < line; ++i)
	{
		for (size_t j = 0; j < column; ++j)
		{
			if (maxElement <= mtrx[i][j])
			{
				maxStringIndex = i;
				maxElement = mtrx[i][j];
			}
		}
	}
	return maxStringIndex;
}

int32_t MaxColumnIndex(int32_t** mtrx, int32_t line, int32_t column)
{
	int32_t maxElement{ mtrx[0][0] };
	int32_t maxColumnIndex{};
	for (size_t i = 0; i < line; ++i)
	{
		for (size_t j = 0; j < column; ++j)
		{
			if (maxElement <= mtrx[i][j])
			{
				maxColumnIndex = j;
				maxElement = mtrx[i][j];
			}
		}
	}
	return maxColumnIndex;
}

void SwithMtrxForMax(int32_t** mtrx, int32_t line, int32_t column)
{
	for (size_t j = 0; j < column; ++j)
	{
		std::swap(mtrx[0][j], mtrx[MaxStringIndex(mtrx, line, column)][j]);
	}
	for (size_t i = 0; i < line; ++i)
	{
		std::swap(mtrx[i][0], mtrx[i][MaxColumnIndex(mtrx, line, column)]);
	}
	PrintMtrx(mtrx, line, column);
}

void CopyMtrx(int32_t** mtrx, int32_t** copyMtrx, int32_t line, int32_t column)
{
	for (size_t i = 0; i < line; ++i)
	{
		for (size_t j = 0; j < column; ++j)
		{
			copyMtrx[i][j] = mtrx[i][j];
		}
	}
}

void DeleteData(int32_t** mtrx, int32_t line)
{
	for (size_t i = 0; i < line; ++i)
	{
		delete[] mtrx[i];
	}
	delete[] mtrx;
}