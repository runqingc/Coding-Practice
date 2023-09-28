#include <iostream>
#include <string>
using namespace std;

string replaceSpace(string s) {
    string ans;
    for(auto c: s){
        if(c==' '){
            ans += "%20";
        }else{
            ans += c;
        }
    }
    return ans;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
