#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

template <class type>
bool equal(type a, type b) {
  if (a == b) {
    return true;
  }
  return false;
}

bool equal(double a, double b) {
  setprecision(8);
  double tolerance = 0.00001;

  if (abs(a - b) < tolerance) {
    return true;
  }
  return false;
}

int main() {
  // not equal float numbers
  double a = 1.11;
  double b = 0.11;
  cout << a << " == " << b;
  if (equal(a, b)) {
    cout << ": True" << endl;
  } else {
    cout << ": False " << endl;
  }

  // Checking precision
  double c = 1.00001;
  double d = 1.000011;
  cout << c << " == " << d;
  if (equal(c, d)) {
    cout << ": True" << endl << endl;
  } else {
    cout << ": False" << endl << endl;
  }


  double e = 1.00001;
  double f = 1.00003;
  cout << e << " == " << f;
  if (equal(e, f)) {
    cout << ": True" << endl << endl;
  } else {
    cout << ": False" << endl << endl;
  }

  // Checking general
  string aa = "Hello world!";
  string aac = "Hello world!";

  cout << aa << " == " << aac;

  if (equal(aa, aac)) {
    cout << ": True" << endl << endl;
  } else {
    cout << ": False" << endl << endl;
  }

  string aaa = "Hello world.";
  string aacc = "Hello world!";

  cout << aaa << " == " << aacc;

  if (equal(aaa, aacc)) {
    cout << ": True" << endl << endl;
  } else {
    cout << ": False" << endl << endl;
  }
}