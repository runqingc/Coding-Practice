#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {

        unordered_map<char, int> umap;
        for(auto c: s){
            if(umap.find(c)==umap.end()){
                umap[c] = 1;
            }else{
                ++umap[c];
            }
        }
        int containOddSum = 0;
        int evenSum = 0;
        for(auto& pair: umap){
            if(pair.second%2==1){
                containOddSum = 1;
                evenSum += pair.second-1;
            }else{
                evenSum += pair.second;
            }
        }

        return evenSum+containOddSum;
    }
};


int main(){

    return 0;
}