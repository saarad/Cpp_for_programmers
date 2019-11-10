//
// Created by Ilia on 10.11.2019.
//

#include "Set.h"
#include <iostream>
#include <string>
#include <set>
#include <vector>


using namespace std;

Set::Set() {
    values = {};
}

Set::Set(vector<int> val) {
    values = val;
}

//This method overloads the "+" operator to find union of two sets
Set Set::operator+(Set &set) const {
    vector<int> unionOfSets;

    //Checking the object calling
    for(auto &val:values){
        if(find(unionOfSets.begin(),unionOfSets.end(),val) == unionOfSets.end()){ //checking for duplicates
            unionOfSets.emplace_back(val);
        }
    }

    //Checking the object on added
    for(auto &val:set.getValues()){
        if(find(unionOfSets.begin(),unionOfSets.end(),val) == unionOfSets.end()){ //checking if value already added
            unionOfSets.emplace_back(val);
        }
    }

    vector<int> newValues(unionOfSets.begin(), unionOfSets.end()); //creating new vector
    Set newSet(newValues); //creating new set
    return newSet;
}

Set Set::operator+(int value) const {
    Set s = *this; //reference to be able to change values
    if(find(s.values.begin(), s.values.end(), value) == s.values.end()){
        s.values.emplace_back(value);
    }
    return s;
}

Set &Set::operator=(const Set &set) { //redundant, but the implemented for exercise purposes
    values = set.values;
    return *this; //returning instead of having void function, so we can chain multiple assigns (e.g. set1 = set2 = set3)
}
