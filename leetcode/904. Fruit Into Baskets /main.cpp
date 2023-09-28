#include <iostream>
#include <vector>
using namespace std;

int totalFruit(vector<int>& fruits) {
    if(fruits.size()==1) return 1;
    int fast = 1; int cnt = 1; int max = 0;
    pair<int, int> b0 {fruits[0], 1}, b1{-1, 0};
    int row = 1;
    for( ; fast<fruits.size(); ++fast){
        if(fast-1==0){
            row = 1;
        }else{
            if(fruits[fast-2]==fruits[fast-1]){
                ++row;
            }else{
                row = 1;
            }
        }

        // find a new tree
        // case 1, meet the same tree
        if(fruits[fast]==b0.first){
            ++cnt; ++b0.second;
        }else if(fruits[fast]==b1.first){
            ++cnt; ++b1.second;
        }
        // case 2, meet a different tree
        else{
            // case2.1 if there's empty basket
            if(b1.first==-1){
                b1.first = fruits[fast];
                b1.second = 1;
                ++cnt;
            }else{
                //case 2.2 if no empty basket, discard the fruit not produced by fruits[fast-1]
                if(b0.first!=fruits[fast-1]){
                    cnt-=b0.second;
                    b0.first = fruits[fast];
                    b0.second = 1;
                    b1.second = row;
                    cnt = row+1;
                }else{
                    cnt-=b1.second;
                    b1.first = fruits[fast];
                    b1.second = 1;
                    b0.second = row;
                    cnt = row+1;
                }
            }
        }

        if(cnt>max){
            max = cnt;
        }

    }

    return max;
}

int main() {
    vector<int> fruits{1,0,1,4,1,4,1,2,3};
    std::cout << totalFruit(fruits)<< std::endl;
    return 0;
}
