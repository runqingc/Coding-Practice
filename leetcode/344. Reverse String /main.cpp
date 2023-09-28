#include <iostream>
#include <vector>
using namespace std;

void reverseString(vector<char>& s) {
    int l=0, r = (int)s.size()-1;
    while(l<r)swap(s[l++], s[r--]);
}


int main() {
    vector<char> s{'H','a','n','g','z','h','o','u'};
    reverseString(s);
    for(char c: s){
        cout << c;
    }
    return 0;
}
