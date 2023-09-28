#include <iostream>
#include <string>
using namespace std;

bool check(string s){
    int i=0, j =s.length()-1;
    while(i<j){
        if(s[i]!=s[j]) return false;
        i++, j--;
    }
    return true;
}

bool validPalindrome(string s) {
    string s_copy(s);
    int i=0, j =s.length()-1;
    while(i<j){
        if(s[i]!=s[j]) {
            s_copy.erase(i,1);
            if(check(s_copy)) return true;
            s_copy = s;
            s_copy.erase(j,1);
            if(check(s_copy)) return true;
            else return false;
        }
        i++, j--;
    }
    return true;
}

int main() {
    cout << validPalindrome("abc") << endl;
    return 0;
}
