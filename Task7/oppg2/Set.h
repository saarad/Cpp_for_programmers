//
// Created by Ilia on 10.11.2019.
//

#include <vector>
#include <iostream>
#ifndef SET
#define SET
class Set{
public:
    Set(); //create empty set
    explicit Set(std::vector<int> values); //Create set with given values. Explicit to not allow implicit conversions
    Set operator+(Set &set) const;
    Set operator+(int value) const;
    Set &operator=(const Set &set);
    std::vector<int>getValues(){return values;}; //defining directly in declaration

private:
    std::vector<int> values;

};
#endif