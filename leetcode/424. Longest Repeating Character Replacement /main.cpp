#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

bool isLegal(unordered_map<char, int>& dict, int k, int sum){
    int max = -1;
    for(auto i = dict.begin(); i!=dict.end(); ++i){
        if(i->second>max) max = i->second;
    }
    return sum-max<=k;
}


int characterReplacement(string s, int k) {
    unordered_map<char, int> dict;
    auto i = s.begin();
    auto j = i;
    int max=0;
    int sum=0;

    for( ; j!=s.end(); ++i){
        if(i!=s.begin()){
            if(dict[*i]>0){
                dict[*i]--;
                --sum;
            }
            else dict.erase(*i);
        }
        for( ; j!=s.end(); ++j){
            if()

            if(dict.find(*j)!=dict.end()){
                dict[*j]++;
                sum++;
                if(sum>max) max = sum;
            }else{
                if(dict.size()<=k){
                    dict[*j] = 1;
                    sum++;
                    if(sum>max) max = sum;
                }else{
                    --j;
                    break;
                }
            }
        }
    }
    return max;
}




int main() {
    cout << characterReplacement("AABABBA", 1);
    return 0;
}
