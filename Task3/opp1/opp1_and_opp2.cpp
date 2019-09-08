#include <iostream>

const double pi = 3.141592;
using namespace std;

//Opp1
class Circle {
public:
    Circle(double radius_);
    double get_area() const; //changed to double from int, to prevent loss
    double get_circumference() const;
//private double radius; //Can't define private member inside public members

private:
    double radius;
};

// ==> Implementasjon av klassen Circle

Circle::Circle(double radius_) : radius(radius_) {} //changed radius to radius_

double Circle::get_area() const{
    return pi * radius * radius;
}

double Circle::get_circumference() const {
    double circumference = 2.0 * pi * radius; //put double behind circumference
    return circumference;
}

//Opp2
int main(){
    Circle circle(5);

    double area = circle.get_area();
    cout << "Arealet er lik " << area << endl;

    double circumference = circle.get_circumference();
    cout << "Omkretsen er lik " << circumference << endl;
}