#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

string replaceWords(vector<string>& dictionary, string& sentence) {
    unordered_set<string> dict;
    for(auto& word: dictionary){
        dict.insert(word);
    }
    string word;
    string ans;
    for(unsigned i =0; i<sentence.size(); ++i){
        if(sentence[i]!=' '){
            word+=sentence[i];
            if(dict.find(word)!=dict.end()){
                ans+=word;
                ans+=' ';
                while(sentence[i]!=' '){
                    ++i;
                }
                word = "";
            }
        }else{
            ans+=word;
            ans+=' ';
            word="";
        }
    }
    if(!word.empty()){
        ans+=word;
    }
    while (ans.back()==' '){
        ans.pop_back();
    }
    return ans;
}







int main() {
    vector<string> dictionary {"cat","bat","rat"};
    string sentence = "the cattle was rattled by the battery";
    cout << replaceWords(dictionary, sentence);

    return 0;
}
