#include <iostream>
using namespace std;

void count(){
    int x, y, z;
    int cnt = 0;
    for(x=0; x<=13; ++x){
        for(y=0; y<=13-x; ++y){
            z = 13-x-y;
            cout << x << " " << y << " " << z << endl;
            ++cnt;
        }
    }
    cout << cnt;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    count();
    return 0;
}
