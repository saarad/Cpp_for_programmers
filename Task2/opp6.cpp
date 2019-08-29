// opp6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int find_sum(const int *table, int length);

int main()
{
	const int length = 20;
	int table[length];
	for (int i = 0; i < length; i++) { //initialize the table
		table[i] = i;
	}
	std::cout << "Sum of first 10 elements: " << find_sum(table, 10) << "\n";
	std::cout << "Sum of next 5 elements: " << find_sum(&table[10], 5) << "\n";
	std::cout << "Sum of last elements: " << find_sum(&table[15], 5)<< "\n";
}

int find_sum(const int *table, int length) {
	int sum = 0;
	for (int i = 0; i < length; i++) {
		sum += table[i];
	}
	return sum;
}