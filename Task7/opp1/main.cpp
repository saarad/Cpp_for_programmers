//
// fraction/main.cpp
//
#include "fraction.h"
#include <iostream>
#include <string>

using namespace std;

void print(const string &text, const Fraction &broek) {
    cout << text << broek.numerator << " / " << broek.denominator << endl;
}

int main() {
    Fraction a(10, 20);
    Fraction b(3, 4);
    Fraction c;
    c.set(5);
    Fraction d = a / b;

    print("a = ", a);
    print("b = ", b);
    print("c = ", c);
    print("d = ", d);

    b += a;
    ++c;
    d *= d;

    print("b = ", b);
    print("c = ", c);
    print("d = ", d);

    c = a + b - d * a;
    c = -c;

    print("c = ", c);

    if (a + b != c + d)
        cout << "a + b != c + d" << endl;
    else
        cout << " a + b == c + d" << endl;
    while (b > a)
        b -= a;
    print("b = ", b);

    //oppg a
    Fraction e(0,1);
    e = a+b;
    print("e = a + b = ", e); //should be the same as b += a

    e = Fraction(0,1); //reset

    e = e + 1; //should be 1/1
    print("e + 1 = ", e);

    e = Fraction(0,1);//reset
    e = 1 + e; //should be the same as e + 1
    print("1 + e = ", e);

    e = e-1; //should be 0/1
    print("e - 1 = ", e);

    ++e;
    e = 1333 - e; //should be 1332/1
    print("1333 - e = ", e);

    
    //oppg b
    e = Fraction(10,1); //reset
    Fraction f(10,1);

    //e = 5 - 3 - e - 7 - f. This will be compiled as e = (5-3) - (e).
    // Then e = e - 7.  And in the end e = e - f. Like this:

    int integer = 5-3; //standard operator for integer used
    e = integer - e; //The version used is Fraction operator-()
    e = e - 7; //The version used is Fraction operator-(int)
    e = e - f; //The version used is Fraction operator-(Fraction, Fraction)
    print("e = 5 - 3 - e - 7 - f = ", e);

    //Checking logic
    e = Fraction(10,1); //reset
    e = 5 - 3 - e - 7 - f;
    print("Checking logic.. e should be the same, e is: ", e );

    //Changing the order will give different result because of associativity
    e = Fraction(10,1); //reset
    e = 5 - e - 7 - f - 3; //is compiled as e = ( ((5-e)-7) -(f)) - 3
    print("e = 5 - e - 7 - f - 3 = ", e);

}