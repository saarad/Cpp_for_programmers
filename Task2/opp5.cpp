// opp5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

 void assign(double *number);
int main()
{
	

	//Method 1
	double number;
	double *number_pointer = &number;
	*number_pointer = 1;
	std::cout << number;

	//Method 2
	number = 1; //directly assigning 
	std::cout << number;

	//Method 3
	assign(&number); //sends in the adress of number
	std::cout << number;

	


}

void assign(double *number) { //takes in a adress for a float, we're really doing the same at method 1
	*number = 3;
}