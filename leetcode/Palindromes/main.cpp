#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s){
    if(s.size()==1){
        return true;
    }else if(s.size()==2){
        return s.front()==s.back();
    }else{
        return s.front()==s.back() && isPalindrome(s.substr(1,s.size()-2));
    }
}


int main() {

    string s;
    cin >> s;
    if(isPalindrome(s)){
        cout << "PALINDROME";
    }else{
        cout << "NOT PALINDROME";
    }

    return 0;
}
