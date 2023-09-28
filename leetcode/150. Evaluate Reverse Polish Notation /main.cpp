#include <iostream>
#include <string>
#include <stack>
using namespace std;

int evalRPN(vector<string>& tokens) {
    stack<int> s;
    int num1, num2;
    for(auto& i: tokens){
        if(i=="+"){
            num1 = s.top(); s.pop();
            num2 = s.top(); s.pop();
            s.push(num1+num2);
        }else if(i=="-"){
            num1 = s.top(); s.pop();
            num2 = s.top(); s.pop();
            s.push(num2-num1);
        }else if(i=="*"){
            num1 = s.top(); s.pop();
            num2 = s.top(); s.pop();
            s.push(num1*num2);
        }else if(i=="/"){
            num1 = s.top(); s.pop();
            num2 = s.top(); s.pop();
            s.push(num2/num1);
        }else{
            s.push(stoi(i));
        }
    }
    return s.top();
}


int main() {
    vector<string> tokens{"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    cout << evalRPN(tokens);

    return 0;
}
