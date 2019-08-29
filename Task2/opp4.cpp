// opp4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	int a = 5;
	int *a_pointer = &a;
	int b = 2;
	//int &b; //This will not work because b hasn't been initialized (so it will have no adress)
	//int *c; // dangerous, should be pointing to something when initialized or it will be allocated to a random place in memory 
	int *c = &b;
	*a_pointer = *c + *c;
	// &b = 2 //&b is the memory adress of b, 2 is an invalid property
	*c = 2;
}

