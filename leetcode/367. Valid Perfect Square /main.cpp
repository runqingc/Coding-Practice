#include <iostream>
using namespace std;


// binary search all numbers between [1, num/2]
#define ll long long
bool isPerfectSquare(int num) {
    if(num==1) return true;
    ll l=1, r = num/2;
    while(l<=r){
        ll mid = (l+r)/2;
        ll square = mid*mid;
        if(square==num){
            return true;
        }else if(square>num){
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return false;
}


int main() {
    cout << isPerfectSquare(2);
    return 0;
}
