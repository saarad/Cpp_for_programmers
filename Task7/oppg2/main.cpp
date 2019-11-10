#include <iostream>
#include <vector>
#include "Set.h"

using namespace std;

ostream &operator<<(ostream &stream, Set &set) { //overloading cout<< for Set-objects
    stream << "{";
    vector<int> values = set.getValues();
    for(auto &val : values) {
        stream << val;
        if(&val != &values.back()) {
            stream << ", ";
        }
    }
    stream << "}";
    return stream;
}

int main() {
    vector<int> values = {1, 3, 4, 5, 7};
    Set set1;
    Set set2(values);

    cout << "Values in empty set 1: " << set1 << endl;
    cout << "Values in set 2: " << set2 << endl;

    //inserting value into set 1
    set1 = set1 + 6;
    cout<<"Set 1 now has now values: " << set1 << endl;

    //union of the sets
    Set unionSet = set1 + set2;
    cout << "Union of the sets is: " << unionSet << endl;

    //checking if duplicates are not added
    unionSet = unionSet + 1;
    cout << "Tried to insert duplicate value. The union set is: " << unionSet << endl;
    unionSet = unionSet + set2;
    cout << "Tried to insert multiple duplicate values. The union set is: " << unionSet << endl;

    //setting set 1 and 2 as union set
    set1 = set2 = unionSet;
    cout<<"All sets have now the same values as union set. \nSet 1: " << set1 << "\nSet 2: " << set2
    << "\nUnion set: " << unionSet;
}