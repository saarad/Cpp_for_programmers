#include "pch.h"
#include <fstream>
#include <iostream>


using namespace std;

void read_temperatures(double temps[], int length);

int main() {
	const int length = 5;
	const char filename[] = "tempfile.txt";
	std::ifstream file;
	file.open(filename);
	double temps[length];

	if (!file) {
		cout << "Error opening file ";
		exit(EXIT_FAILURE);
	}

	int number;
	int counter = 0;
	while (file >> number) {
		temps[counter] = number;
		counter++;
	}
	read_temperatures(temps, length);
}

void read_temperatures(double temps[], int length) {
	int tempUnder10 = 0;
	int tempBet1020 = 0;
	int tempOver20 = 0;

	for (int i = 0; i < length; i++) {
		cout << "Temp " << (i + 1) << " is " << temps[i] << endl;
		if (temps[i] < 10)tempUnder10++;
		else if (temps[i] >= 10 && temps[i] <= 20) tempBet1020++;
		else tempOver20++;
	}


	std::cout << "\n\nTemp under 10 is: " << tempUnder10 << std::endl;
	std::cout << "Temp between 10 and 20 is: " << tempBet1020 << std::endl;
	std::cout << "Temp over 20 is: " << tempOver20;

}