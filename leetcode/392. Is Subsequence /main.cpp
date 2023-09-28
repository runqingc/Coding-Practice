#include <iostream>
#include <string>
using namespace std;


bool isSubsequence(string s, string t) {
    auto i = t.begin();
    auto j = s.begin();
    for(; j<s.end() && i<t.end(); ++j){
        while(*i!=*j){
            ++i;
            if(i==t.end()) return false;
        }
        ++i;
    }
    if(j==s.end())return true;
    return false;
}


int main() {
    string s = "axc", t = "ahbgdc";
    cout << isSubsequence(s,t);
    return 0;
}
