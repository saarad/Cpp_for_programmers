// opp1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>

int main()
{
	//A

	int i = 3;
	int j = 5;
	int *p = &i; 
	int *q = &j;
	std::cout << "Adress i and *p: " << &i << "\n"; //p points to i's adress, &i and p print the same
	std::cout << "Adress j and *q: " << q << "\n"; //q points to j's adress, q and &j print the same

	//B

	*p = 7; //i is now 7
	*q += 4; //j is now 9
	*q = *p + 1; //j is now 8
	p = q; //*p is now equal to *q, because they both point to j's adress
	std:: cout << " p and q are now equal: " << *p << " " << *q << std::endl; //they are both 8
	std::cout << "Adress p, q and j: " << p << std::endl;
	std::cout << "Adress i (i has no pointer right now) " << &i << "\nAnd value i:  " << i << "\nBut p,q,j: " << *p <<"\n\n";

	

}

