#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addBinary(string a, string b) {
    int max_length = (int)max(a.length(), b.length());
    int carry = 0;
    string ans;
    for(int i=0; i<max_length || carry!=0; ++i){
        int op1, op2;
        (a.length()>i)?(op1=(int)(a[a.length()-1-i]-'0')):(op1=0);
        (b.length()>i)?(op2=(int)(b[b.length()-1-i]-'0')):(op2=0);
        switch (4*!!carry + 2*!!op2 + !!op1 ) {
            case 0: ans.insert(0, "0");break;
            case 1:
            case 2:
            case 4: ans.insert(0, "1"); carry = 0; break;
            case 3:
            case 5:
            case 6: ans.insert(0, "0"); carry = 1; break;
            case 7: ans.insert(0, "1"); carry = 1; break;
        }
    }
    return ans;
}




int main() {
    cout << addBinary("0", "0") << endl;
    cout << addBinary("111", "11")<< endl;
    cout << addBinary("10", "1")<< endl;
    cout << addBinary("10101", "11111")<< endl;

    return 0;
}
