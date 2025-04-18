#include <iostream>
#include <deque>
#include <string>
#include <cctype> 
using namespace std;

int main() {
    string sentence = "no lemon no melon";
    //string sentence = "Was it a cat I saw?";
    //string sentence = "this is not a palindrome";
    
    deque<char> d;

    for(int i=0; i<sentence.length(); i++){
        if(isalpha(sentence[i])) { // only check the letters
            d.push_back(tolower(sentence[i]));
        }
    }

    cout << "\"" << sentence  << "\"" << " is";
    while(d.size() > 1){
        if(d.front() != d.back()){
            cout << " not";
            break;
        } else {
            d.pop_front();
            d.pop_back();
        }
    }

    cout << " a palindrome" << endl;
    return 0;
}

