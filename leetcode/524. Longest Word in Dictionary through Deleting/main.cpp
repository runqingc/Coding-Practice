#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string findLongestWord(string s, vector<string>& dictionary) {
    sort(dictionary.begin(), dictionary.end(), [&](const string& s1, const string& s2)->bool{
        return s1.length()>s2.length() || (s1.length()==s2.length() && s1<s2);
    } );
    int i, j;
    // try to match every string in the dictionary
    for(auto& iter: dictionary){
        i= 0; j = 0;
        while(i<iter.length() && j<s.length()){
            if(iter[i]==s[j]){
                ++i; ++j;
            }else{
                ++j;
            }
        }
        if(i==iter.length()) return iter;
    }
    return "";
}

int main() {
    string s = "abpcplea";
    vector<string> dictionary {"ale","apple","monkey","plea"};
    cout << findLongestWord(s, dictionary) << endl;
    return 0;
}
