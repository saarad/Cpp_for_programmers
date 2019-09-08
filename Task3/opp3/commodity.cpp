//
// Created by Ilia on 08.09.2019.
//

//
// NB! If using CMakeLists, remember to add the class to executable (project targets)
//
#include "commodity.h"
#include <string>

using namespace std;
const double tax_const = 0.25; //standard norwegian taxes on items sold

Commodity::Commodity(const string name_, const int id_, double price_): name(name_), id(id_), price(price_) {}

const string Commodity::get_name()const{
    return name;
}

const int Commodity::get_id()const{
    return id;
}

double Commodity::get_price(){ //returns price pr Kilo
    return price;
}

double Commodity::get_price(double quantity)const{ //returns total price without taxes
    return price*quantity;
}

void Commodity::set_price(double new_price){
    price = new_price;
}

double Commodity::get_price_with_sales_tax(double quantity){
    double tax = quantity*price*tax_const;
    return price*quantity+tax;
}