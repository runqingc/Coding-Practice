#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
//findResultantString

int getMinSum(vector<int>& security_values, string& s){
    sort(s.begin(), s.end(), [&security_values](char a, char b){
        return security_values[a-'a']<security_values[b-'a'];
    });
    int sum = 0;
    for(int i=1; i<s.size(); ++i){
        sum += (int)(security_values[s[i]-'a']-security_values[s[i-1]-'a']);
    }
    return sum;
}


int main() {
    string s = "qaafebdhui";
    vector<int> secure{1, 2, 1, 3, 1, 3, 5, 7, 1, 1, 5, 5, 8, 10, 11, 1, 23, 2, 3, 7, 8, 9, 1, 6, 5, 9};
    cout << getMinSum(secure, s);
    return 0;
}
