#include <iostream>

void outField(char** field, const int SIZE)
{
	for (auto ix = 0; ix < SIZE; ++ix)
	{
		for (auto jx = 0; jx < SIZE; ++jx)
		{
			std::cout << field[ix][jx] << '|';
		}
		std::cout << std::endl;
	}
}

void TicTacToe()
{
	const int SIZE = 3;
	char** field = new char* [SIZE];

	for (auto ix = 0; ix < SIZE; ++ix)
	{
		field[ix] = new char[SIZE];
	}

	char ch = 48;
	for (auto ix = 0; ix < SIZE; ++ix)
	{
		for (auto jx = 0; jx < SIZE; ++jx)
		{
			field[ix][jx] = ch++;
		}
	}

	bool b = true;

	int i, j, count = 0;
	int rand1, rand2;

	while (b)
	{
		std::cout << "Enter numbers:" << std::endl;
		std::cin >> i >> j;

		if (field[i][j] != 'o') field[i][j] = 'x';
		else {
			std::cout << "Please Enter numbers:" << std::endl;
			std::cin >> i >> j;
		}

		rand1 = (rand() + count) % SIZE;
		rand2 = (rand() + count) % SIZE;

		if (field[rand1][rand2] != 'x') field[rand1][rand2] = 'o';
		else {
			++count;
			rand1 = (rand() + count) % SIZE;
			rand2 = (rand() + count) % SIZE;
		}

		outField(field, SIZE);

		if (field[0][0] == field[0][1] && field[0][1] == field[0][2]) b = false;
		if (field[1][0] == field[1][1] && field[1][1] == field[1][2]) b = false;
		if (field[2][0] == field[2][1] && field[2][1] == field[2][2]) b = false;

		if (field[0][0] == field[1][1] && field[1][1] == field[2][2]) b = false;
		if (field[2][0] == field[1][1] && field[1][1] == field[0][2]) b = false;
	}

	std::cout << "Game Over!";

	for (int ix = 0; ix < SIZE; ++ix)
	{
		delete[] field[ix];
	}
	delete[] field;
}

int main()
{
	TicTacToe();
}