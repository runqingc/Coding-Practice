#include <iostream>
#include <string>
using namespace std;

string reverseLeftWords(string s, int n) {
    int size = (int) s.size();
    for(int i = n-1; i>=0; --i ){
        for(int j = i; j<i+size-n; ++j){
            swap(s[j], s[j+1]);
        }
    }
    return s;
}



int main() {
    string s = "la"; int k = 1;
    std::cout << reverseLeftWords(s, k) << std::endl;
    return 0;
}
