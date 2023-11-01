#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        auto meta = static_cast<unsigned char>(strs.size());
        string ans;
        ans += static_cast<char>(meta);
        for(auto& str: strs){
            auto size = static_cast<unsigned char>(str.size());
            ans+= static_cast<char>(size);
        }
        for(auto& str: strs){
            ans += str;
        }
        return ans;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> ans;
        auto sum = static_cast<int>(static_cast<unsigned char>(s[0]));
        int ptr = 1+sum;
        for(int i=1; i<1+sum; ++i){
            auto size = static_cast<int>(static_cast<unsigned char>(s[i]));
            ans.emplace_back(s.substr(ptr, size));
            ptr+=size;
        }
        return ans;
    }
};


int main() {
    vector<string> strs{"Hello", "World"};
    Codec codec;
    auto res =  codec.decode(codec.encode(strs));
    for(auto& re: res){
        cout << re;
    }
    return 0;
}
