#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main() {
    
    vector<int>d {1,2,3,4};
    
    cout << accumulate(d.begin()+1, d.begin()+1, 0)<< endl;

    int x = 3, y = 5;
    




    return 0;
}