#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string reverseStr(string s, int k) {
    int l = 0, r = min((int)s.size()-1, k-1);
    for( ; ; ){
        // reverse string s[l] to s[r], inclusive
        int i=l, j = r;
        while(i<j) swap(s[i++], s[j--]);
        // place new r and l
        if(r>=(int)s.size()-1)break;
        l+= 2*k;
        r = min((int)s.size()-1, l+k-1);
    }
    return s;
}


int main() {
    string s = "ab";
    int k = 3;
    cout << reverseStr(s,k);
    return 0;
}
