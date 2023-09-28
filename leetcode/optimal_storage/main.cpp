#include <iostream>
#include <string>
#include <vector>
using namespace std;

string optimal(string& s, int k){
    vector<char> dict(26);
    for (int i = 0; i <= 25; ++i)
        dict[i] = (char) ('a' + i);
    char max_char = 'a';
    for(auto c: s){
        if(c>max_char){
            if(c-max_char<=k){
                // update available operation time
                k -= c-max_char;
                // update dict
                for(int i = (int)(c-'a'); i>=max_char-'a'; --i){
                    dict[i] = 'a';
                }
                // update current max_char
                max_char = c;
                if(k==0) break;
            }else{
                // if c-max_char>=k, available operation time not enough
                // update dict
                for(int i = (int)(c-'a'); i>(int)(c-'a')-k; --i){
                    dict[i] = c-k;
                }
                break;
            }
        }
    }
    for(auto i = s.begin(); i<s.end(); ++i){
        *i = dict[*i-'a'];
    }
    return s;
}


int main() {
    vector<pair<string, int>> testcases{{"abcc", 2},
                                        {"abdd", 2},
                                        {"yzwyz", 3},
                                        {"dbefg", 5},
                                        {"abdd", 200},
                                        {"a", 1},
                                        {"abcdef", 1},
                                        {"xyzab", 2},
                                        {"xyxzyz", 3},
                                        {"abcabc", 3},
                                        {"mnopqr", 3},
    };
    for(auto& testcase: testcases){
        cout << testcase.first << ", " << testcase.second << " -> "
        << optimal(testcase.first, testcase.second) << endl;
    }

    return 0;
}
