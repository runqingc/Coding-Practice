#include <iostream>
#include <string>
using namespace std;

string reverse(string s){
    if(s.size()<=1){
        return s;
    }else{
        return reverse(s.substr(1))+s[0];
    }
}


int main() {
    string s;
    cin >> s;
    s = reverse(s);
    cout << s;
    return 0;
}
