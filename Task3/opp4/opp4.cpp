#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string opp4abc(string &word1, string &word2, string &word3);
string opp4d(string &sentence);
void opp4e(string &sentence2);
void opp4f(string &sentence);
void opp4g(string &sentence, string &search);
void opp4h(string &sentence, string &search);

int main() {
    string word1;
    string word2;
    string word3;
    cout<<"Word 1: ";
    cin>>word1;
    cout<<"\nWord 2: ";
    cin>>word2;
    cout<<"\nWord 3: ";
    cin>>word3;
    string sentence = opp4abc(word1, word2, word3);
    string sentence2 = opp4d(sentence);
    opp4e(sentence2);
    opp4f(sentence);
    string search_G = "hallo";
    opp4g(sentence, search_G);
    string search_H = "er";
    opp4h(sentence, search_H);
}

string opp4abc(string &word1, string &word2, string &word3){
    string sentence = word1 + " " + word2 + " " + word3 + ".";
    cout<<"\nYour sentence: " << sentence << endl;
    cout<<"Length of words. \n1: " << word1.length() << "\n2: " << word2.length() << "\n3: "<< word3.length() << endl;
    cout<<"Length of sentence: " << sentence.length() << endl;
    return sentence;
}

string opp4d(string &sentence){
    string sentence2;
    for (char i : sentence) {
        sentence2+= i;
    }
    if(sentence2.length() == sentence.length())cout<<"Sentence copied successfully: " << sentence2 << endl;
    return sentence2;
}

void opp4e(string &sentence2){
    if(sentence2.length()<10){
        cout<<"The sentence has not enough characters for this task (4e)" << endl;
    }
    else if(sentence2.length()>=10 && sentence2.length()<12){
        sentence2[9] = 'x';
        sentence2[10] = 'x';
    }else{
        for(int i = 9; i<12; i++){
            sentence2[i] = 'x';
        }
    }
    cout<<"Sentence 2 in 4e: " << sentence2 << endl;
}

void opp4f(string &sentence){
    if(sentence.length()<=5){
        cout<<"First 5 characters: " << sentence << endl;
    }else{
        string sentence_start;
        for(int i = 0; i<5; i++){
            sentence_start+= sentence[i];
        }

        cout<<"First 5 characters: " << sentence_start << endl;

    }
}

void opp4g(string &sentence, string &search){
    for(int i = 0; i<sentence.length(); i++){ //make sentence to lower case
        sentence[i] = tolower(sentence[i]);
    }
    for(int i = 0; i<search.length(); i++){ //make search to lower case
        search[i] = tolower(search[i]);
    }

    size_t search_pos = sentence.find(search, 0); //find first instance of the search-string
    if(search_pos != string::npos){
        cout<< "\" "<< search << "\"" << " found at " << search_pos << endl;
    }else{
        cout<< "\"" << search<<"\" not found." <<endl;
    }
}

void opp4h(string &sentence, string &search){
    for(int i = 0; i<sentence.length(); i++){ //make sentence to lowercase
        sentence[i] = tolower(sentence[i]);
    }
    for(int i = 0; i<search.length(); i++){ //make search to lowercase
        search[i] = tolower(search[i]);
    }

    int counter = 0;
    size_t search_pos = sentence.find(search, 0);
    if(search_pos == string::npos){ //search is not found, just return.
        cout<<"\"" << search << "\" " << "not found.";
        return;
    }else{
        cout<<"\""<<search<<"\" found at: " << endl;
    }
    while(search_pos!=string::npos){ //Search for every instance of the search-string
        cout<<search_pos<<endl;
        search_pos = sentence.find(search, (counter+1));
        counter = search_pos;
    }
}