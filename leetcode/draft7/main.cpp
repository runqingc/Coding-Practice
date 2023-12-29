#include <iostream>
using namespace std;
class A{
public:
    int num1;
public:
    A() = default;

    A(int n):num1(n){
        cout << num1 <<endl;
    }

};


int main() {
    A a01;
    cout << a01.num1 <<endl;


    return 0;
}
