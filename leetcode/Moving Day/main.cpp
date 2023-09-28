#include<iostream>
using namespace std;
#define ll long long

int main(){

    ll numBox, size;
    ll x, y ,z;
    ll maxSize=0;
    cin >> numBox >> size;
    for(ll i=0; i<numBox; ++i){
        cin >> x >> y >> z;
        if(x*y*z>maxSize){
            maxSize = x*y*z;
        }
    }
    cout << maxSize-size;
    return 0;
}
