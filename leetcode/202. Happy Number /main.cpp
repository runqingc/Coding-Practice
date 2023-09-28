#include <iostream>
#include <unordered_set>
using namespace std;

#define ll long long
ll cal(ll n){
    ll sum = 0;
    for( ;n!=0;n/=10 ){
        sum += ((n%10)*(n%10));
    }
    return sum;
}


bool isHappy(int n) {
    unordered_set<ll> record;
    record.insert(n);
    ll sum = n;
    while(sum!=1){
        sum = cal(sum);
        if(record.find(sum)!=record.end()){
            return false;
        }
        record.insert(sum);
    }
    return true;
}

int main() {
    cout << cal(19) << endl;
    cout << isHappy(19) << endl;


    return 0;
}
