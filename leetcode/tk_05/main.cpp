#include <iostream>
#include <vector>
#include <string>
using namespace std;

string findResultantString(string& s){
    vector<int> table(26, 0);
    for(auto c: s){
        table[c-'a']++;
    }

    int i=0, j=25;
    for( ;i<26 ;++i){
        if(table[i]%2==1) break;
    }
    for( ; j>=0; --j){
        if(table[j]%2==1) break;
    }

    while(i<j){
        table[i]++; table[j]--;
        for( ;i<26 ;++i){
            if(table[i]%2==1) break;
        }
        for( ; j>=0; --j){
            if(table[j]%2==1) break;
        }
    }

    // reconstruct the string
    string ans;
    char center = '#';
    for(int k=0; k<26; ++k){
        if(table[k]%2==0){
           int num = table[k]/2;
           while(num--){
               ans.push_back((char)(k +'a'));
           }
        }else{
            center = (char)(k +'a');
        }
    }
    if(center!='#'){
        ans.push_back(center);
    }
    for(int k=25; k>=0; --k){
        int num = table[k]/2;
        while(num--){
            ans.push_back((char)(k +'a'));
        }
    }
    return ans;
}


int main() {
    vector<string> testcases{"abcdefg","bbcde", "b", "bc", "zyz","wnblhwvfbj", "bbbcccaa", "qagcmikxtm",
                             "dmdhfwidtf", "fhzjjxkgda", "pmiwgzbfme"};

    for(auto testcase: testcases){
        cout << testcase << "  ->  " << findResultantString(testcase) << endl;
    }
    return 0;
}
