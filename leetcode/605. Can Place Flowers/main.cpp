#include <iostream>
#include <vector>
using namespace std;


bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if(flowerbed.size()==1) return ((flowerbed[0]==0)?(n<=1):(n<=0)) ;
    int cnt = 0;
    for(int i=0; i<flowerbed.size(); i++){
        if(flowerbed[i]==0 && ((i==0 && flowerbed[i+1]==0) ||
                (i==flowerbed.size()-1 && flowerbed[i-1]==0) ||
                (i>0 && i<flowerbed.size()-1 && flowerbed[i+1]==0 && flowerbed[i-1]==0))){
            cnt++; flowerbed[i] = 1;
        }
    }
    return cnt>=n;
}


int main() {
    vector<int> flowerbed{1,0,0,0,1};
    std::cout << canPlaceFlowers(flowerbed, 1) << std::endl;
    return 0;
}
