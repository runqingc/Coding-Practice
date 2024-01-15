#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;


class Solution {
public:
    double cal_k(int x1, int y1, int x2, int y2){
        if(y1==y2) return INT32_MAX;
        double ans = 1.0*(x1-x2)/(y1-y2);
        return ans;
    }


    bool inMiddle(int x1, int y1, int mx, int my, int x2, int y2){
        return (mx-x1)*(mx-x2)<=0 && (my-y1)*(my-y2)<=0 && (cal_k(x1, y1, mx, my)==cal_k(mx, my, x2, y2));
    }

    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        if((a==e || b==f) && !(inMiddle(a,b,c,d,e,f))){
            return 1;
        }
        if(fabs(cal_k(c,d,e,f))==1.0 && !inMiddle(c,d,a,b,e,f)){
            return 1;
        }
        return 2;
        
    }
};


int main(){

    Solution s;
    cout << s.minMovesToCaptureTheQueen(1,1,1,4,1,8);


    return 0;
}