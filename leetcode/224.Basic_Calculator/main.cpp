#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        vector<string> stack {"("};
        auto isSign = [](const string& op){
            return op == "+" || op=="(" || op == ")";
        };
        s.append(")");
        
        for(auto c: s){

            if(c==' '){
                continue;
            }else if(c>='0' && c<='9'){
                if(stack.empty() || !isSign(stack.back())){
                    stack.back() += c;
                }else{
                    stack.emplace_back(1, c);
                }
            }else if(c=='+' || c=='('){
                stack.emplace_back(1, c);
            }else if(c== '-'){
                if(stack.empty() || isSign(stack.back())){
                    stack.emplace_back("0");
                }
                stack.emplace_back("+");
                stack.emplace_back(1,c);
            }else if(c==')'){
                
                while(true){
                    if (stack.empty()) break;
                    int num1 = std::stoi(stack.back());  
                    stack.pop_back();
                    if (stack.empty()) break;
                    string op =  stack.back();
                    stack.pop_back();
                    if(op=="("){
                        if(!stack.empty() && stack.back()=="-"){
                            stack.pop_back();
                            num1 = -num1;
                        }
                        stack.push_back(to_string(num1));
                        break;
                    }
                    if (stack.empty()) break;
                    int num2 = std::stoi(stack.back());
                    stack.pop_back();
                    int res;
                    res = num2+num1;
                    
                    if(!stack.empty() && stack.back()=="("){
                        stack.pop_back();
                        if(!stack.empty() && stack.back()=="-"){
                            stack.pop_back();
                            res = -res;
                        }
                        stack.push_back(to_string(res));
                        break;
                    }else if(!stack.empty() && stack.back()=="-"){
                        stack.pop_back();
                        stack.push_back(to_string(-res));
                    }else{
                        stack.push_back(to_string(res));
                    }

                }
            }

        }
        return (stack.empty())?(0):(std::stoi(stack[0]));
    }
};

int main(){

    string s  = "1-(5)";

    Solution s1;
    cout << s1.calculate(s);

    return 0;
}