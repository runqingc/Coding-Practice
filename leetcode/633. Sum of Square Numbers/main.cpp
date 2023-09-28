#include <iostream>

using namespace std;
#define ll long long
bool judgeSquareSum(int c) {
    ll i = 0; ll j = (int)sqrt(c)+1;
    while(i<j){
        ll result = i*i+j*j-c;
        if(result>0){
            j--;
        }else if(result<0){
            i++;
        }else{
            return true;
        }
    }
    return false;
}

int main() {
    std::cout << judgeSquareSum(2147482647) << std::endl;
    return 0;
}
