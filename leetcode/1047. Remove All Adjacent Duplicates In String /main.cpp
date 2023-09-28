#include <iostream>
#include <string>
#include <stack>
using namespace std;

string removeDuplicates(string s) {
    stack<char> s1;
    for(auto c: s){
        if(!s1.empty()&& c==s1.top()){
            s1.pop();
            continue;
        }
        s1.push(c);
    }
    string s2;
    while(!s1.empty()){
        s2 +=s1.top();
        s1.pop();
    }
    if(s2.size()<=1) return s2;
    int l = 0, r = (int)s2.size()-1;
    while(l<r){
        swap(s2[l++], s2[r--]);
    }
    return s2;
}



int main() {
    cout << removeDuplicates("caacbbca");
    return 0;
}
