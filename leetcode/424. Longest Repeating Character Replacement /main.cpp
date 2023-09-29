#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// for every i:
// for every j starting from i:
// if the new place is legal ++j
// if not, j stays in the illegal position and starting moving i right, until the place is legal


int characterReplacement(string s, int k) {
    vector<int> count(26, 0);
    int sum = 0;
    int max=0;
    auto i = s.begin();
    auto j = s.begin();
    for( ; i!=s.end(); ){
        if(sum-(*max_element(count.begin(), count.end()))<=k){
            // if legal, move j right
            // else, move i right
            if(j!=s.begin()) ++j;
            for( ;j!=s.end(); ++j){
                ++count[*j-'A'];
                ++sum;
                // if legal
                int mode = *max_element(count.begin(), count.end());
                if(sum-mode<=k){
                    if(j-i+1>max){
                        max = j-i+1;
                    }
                }else{
                    break;
                }
            }
            if(j==s.end())break;
        }
        --count[*i-'A'];
        --sum;
        ++i;
    }
    return max;
}



int main() {
    cout << characterReplacement("ABAA", 0);
    return 0;
}
