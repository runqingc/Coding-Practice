#include <iostream>
using namespace std;


int main() {
    int a, b ,c;
    cin >> a >> b >> c;
    if(a>31){
        cout << "Format #3";
    }else if(a>12 && a<=31){
        if(c>31){
            cout << "Format #2";
        }else{
            cout << "Ambiguous";
        }
    }else{
        if(b>12){
            cout << "Format #1";
        }else{
            cout << "Ambiguous";
        }
    }
    return 0;
}
