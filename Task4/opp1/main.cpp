#include <algorithm> 
#include <iostream>
#include <vector> 

using namespace std;

int main() {
    vector<double> numbers = {0.1, 0.2, 0.3, 0.4, 0.5};
    numbers.emplace(numbers.begin()+1, 0.4);
    cout<<"Your front: " << numbers.front() << endl; //Output should be 0.1
    cout<<"Your end: " << numbers.back() << endl; //Output should be 0.5
    cout <<"New element: " << numbers[1] << endl; //Output should be 0.4

    auto it = find(numbers.begin(), numbers.end(), 0.6); //Element should not be found
    if(it != numbers.end()){
        cout<< "Element found: " << *it << endl;
    }else{
        cout << "Element not found" << endl;
    }

    auto it_1 = find(numbers.begin(), numbers.end(), 0.3); //Element should be found
    if(it_1 != numbers.end()){
        cout<< "Element found: " << *it_1 << endl;
    }else{
        cout << "Element not found" << endl;
    }

    auto it_2 = find(numbers.begin(), numbers.end(), 0.5); //Logic also works for last element
    if(it_2 != numbers.end()){
        cout<< "Element found: " << *it_2;
    }else{
        cout << "Element not found";
    }
}