#include <iostream>
#include "pair.cpp"
/*
 * This code is included in the task given, and when it runs and outputs the text commented out below, the task is done.
 *
 * The prerequisite for this task is that the classes we are feeding the pair class can be compared (like int and double
 * which is the case for this task).
 * We also require that the operators +=, + and - is implemented for the classes that are used, which is also the case
 * for this task (int and double are the classes used).
 */

using namespace std;
int main() {
    Pair<double, int> p1(3.5, 14);
    Pair<double, int> p2(2.1, 7);
    cout << "p1: " << p1.first << ", " << p1.second << endl;
    cout << "p2: " << p2.first << ", " << p2.second << endl;

    if (p1 > p2)
        cout << "p1 er størst" << endl;
    else
        cout << "p2 er størst" << endl;

    auto sum = p1 + p2;
    cout << "Sum: " << sum.first << ", " << sum.second << endl;
}

/* Utskrift:
p1: 3.5, 14
p2: 2.1, 7
p1 er størst
Sum: 5.6, 21
*/