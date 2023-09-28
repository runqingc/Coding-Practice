#include <iostream>

// binary search [1, x]
#define ll long long
int mySqrt(int x) {
    if(x<=1) return x;
    ll l=1, r=x/2+1, mid;
    while(r-l>1){
        mid = (r+l)/2;
        ll square = mid*mid;
        if(square<=x && ((mid+1)*(mid+1)>x)){
            return mid;
        }else if(square>x){
            r=mid;
        }else{
            l =mid;
        }
    }
    return l;
}

int main() {
    for(int x=0; x<50; x++){
        std::cout << x << " " << mySqrt(x) << std::endl;
    }

    return 0;
}
