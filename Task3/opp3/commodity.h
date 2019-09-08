//
// Created by Ilia on 08.09.2019.
//

#pragma once

#include <string>

using namespace std;

class Commodity {
public:
    Commodity( string name_,  int id_, double price_);
    const string &get_name()const;
    const int get_id() const;
    double get_price(double quantity)const;
    double get_price();
    void set_price(double new_price);
    double get_price_with_sales_tax(double quantity);

private:
    string name;
    int id;
    double price;
};