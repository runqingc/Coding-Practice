#include <iostream>
#include <string>
#include <algorithm>
using namespace std;


string addStrings(const string& num1, const string& num2) {
    int max_size = (int)max(num1.size(), num2.size());
    int carry = 0;
    int n1, n2;
    string ans;

    for(int i=1; i<=max_size; ++i){
        (num1.size()>=i)?(n1 = num1[num1.size()-i]-'0'):(n1=0);
        (num2.size()>=i)?(n2 = num2[num2.size()-i]-'0'):(n2=0);
        ans.insert(0, 1, (char)((n1+n2+carry)%10+'0'));

        carry = (n1+n2+carry)/10;
    }
    if(carry!=0){
        ans.insert(0, 1, (char)(carry+'0'));

    }
    return ans;
}


int main() {
    cout << addStrings("9999", "1");
    return 0;
}
