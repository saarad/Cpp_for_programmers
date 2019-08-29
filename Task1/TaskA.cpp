// Task1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int etetetrte;

int main()
{
	int tempUnder10 = 0;
	int tempBet1020 = 0;
	int tempOver20 = 0;

	for (int i = 0; i < 5; i++) {
		double x;
		std::cout << "Write in a chosen temp: ";
		std::cin >> x;
		std::cout << "\nChosen temp " << (i + 1) << ": " << x << std::endl;
		if (x < 10)tempUnder10++;
		else if (x >= 10 && x <= 20) tempBet1020++;
		else tempOver20++;
	}

	std::cout << "\n\nTemp under 10 is: " << tempUnder10 << std::endl;
	std::cout << "Temp between 10 and 20 is: " << tempBet1020 << std::endl;
	std::cout << "Temp over 20 is: " << tempOver20;

}