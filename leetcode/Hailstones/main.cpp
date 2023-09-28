#include <iostream>
using namespace std;
#define ll long long

ll SumHailstones(ll x){
    if(x==1) {
        return 1;
    }else if(x%2==0){
        return x+ SumHailstones(x/2);
    }else{
        return x+ SumHailstones(3*x+1);
    }
}

int main() {
    ll x;
    cin >> x;
    cout << SumHailstones(x);
    return 0;
}
