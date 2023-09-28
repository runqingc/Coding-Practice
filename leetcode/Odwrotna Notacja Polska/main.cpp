#include <iostream>
#include <string>
#include <stack>
using namespace std;

#define BOOL 0
#define NUM 1
#define LOP 2
#define AOP 3

int checkType(string& s){
    if(s[0]>='0' && s[0]<='9'){
        return NUM;
    }else if(s=="true" || s== "false"){
        return BOOL;
    }else if(s=="or" || s=="and"){
        return LOP;
    }else{
        return AOP;
    }
}

int b(string& s){
    if(s=="true") return 1;
    else return 0;
}

int main() {
    cout << (3.29+2.79)/10.57*11.43;
    stack<string> s;
    string t; char c;
    while(true){
        cin>> t;
        int type = checkType(t);
        if(type==NUM || type ==BOOL) {
            s.push(t);
        }else{
            if(s.size()<2){
                cout << "SYNTAX ERROR" << endl; return 0;
            }
            string op1, op2;
            op1 = s.top(); s.pop();
            op2 = s.top(); s.pop();
            if(checkType(op1)!= checkType(op2)){
                cout << "TYPE ERROR" << endl; return 0;
            }
            if(checkType(op1)==NUM && type == LOP){
                cout << "TYPE ERROR" << endl; return 0;
            }
            if(checkType(op1)==BOOL && type == AOP){
                cout << "TYPE ERROR" << endl; return 0;
            }
            // eval
            if(t == "+"){
                s.push(to_string(stoi(op1)+stoi(op2)));
            }else if(t =="*"){
                s.push(to_string(stoi(op1)*stoi(op2)));
            }else if( t=="=="){
                if(stoi(op1)-stoi(op2)==0){
                    s.emplace("true");
                }else{
                    s.emplace("false");
                }
            }else if( t=="OR"){
                int ans = b(op1) || b(op2);
                if(ans==1) s.emplace("true");
                else s.emplace("false");
            }else{
                int ans = b(op1) && b(op2);
                if(ans==1) s.emplace("true");
                else s.emplace("false");
            }

        }

        c = (char)getchar();
        if(c!=' ') break;
    }
    if(s.size()!=1){
        cout << "SYNTAX ERROR" << endl; return 0;
    }
    cout << s.top();
    return 0;
}
