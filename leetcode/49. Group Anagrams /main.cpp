#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, int> allStrings;
    vector<vector<string>> ans;
    for(auto& s: strs){
        string s_copy =s;
        std::sort(s_copy.begin(), s_copy.end());
        if(allStrings.find(s_copy)==allStrings.end()){
            allStrings[s_copy] = (int)ans.size();
            vector<string> tmp(1, s);
            ans.emplace_back(tmp);
        }else{
            ans[allStrings.find(s_copy)->second].push_back(s);
        }
    }
    return ans;
}


int main() {
    vector<string> strs{"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> ans = groupAnagrams(strs);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
