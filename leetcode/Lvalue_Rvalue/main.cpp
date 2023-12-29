#include <iostream>
using namespace std;

int main(){

    // lvalue
    int num = 9;
    // lvalue reference
    int& a = num; //不占用额外内存空间，只是num的别名

    // rvalue
    // 不能取地址，只能读
    // e.g, 8
    
    
    // rvalue reference
    // 只能用右值初始化右值引用，不能用右值引用来初始化右值引用
    int&& b = 8;

    // const lvalue reference
    // c 是num的别名，但是不能通过c来修改num的值
    // c = 11 报错
    const int& c = num;

    // const rvalue reference
    // 可以通过右值来初始化，但是不能用右值引用来初始化
    const int&& d = 6;




    return 0;
}


