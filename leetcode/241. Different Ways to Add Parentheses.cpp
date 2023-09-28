#include<vector>
#include<string>
using namespace std;


class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int len = expression.length();
        vector<int> result;
        
        int flag = 0;
        vector<int> left; vector<int> right;
        int l_size=0, r_size = 0;
        for(int i = 0; i<len; i++){
            char c = expression[i];
            if(c=='+' || c=='-' || c=='*'){
                left = diffWaysToCompute(expression.substr(0, i));
                right = diffWaysToCompute(expression.substr(i+1, len-1-i));
                l_size = left.size(); 
                r_size = right.size();
                flag = 1;
            }else{
                continue;
            }
            switch (c)
            {
            case '+':
                for(int j=0; j<l_size; j++){
                    for(int k=0; k<r_size; k++){
                        result.push_back(left[j]+right[k]);
                    }
                }
                break;
            case '-':
                for(int j=0; j<l_size; j++){
                    for(int k=0; k<r_size; k++){
                        result.push_back(left[j]-right[k]);
                    }
                }
                break;
            
            case '*':
                for(int j=0; j<l_size; j++){
                    for(int k=0; k<r_size; k++){
                        result.push_back(left[j]*right[k]);
                    }
                }
                break;
            }
            
        }
        if(flag==0){
            result.push_back(stoi(expression));
            return result;
        }


        return result;
    }
};
