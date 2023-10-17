#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
#define MAGIC 2001
    void rotate(vector<vector<int>>& matrix) {

        int n = (int)matrix.size();
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                matrix[i][j] += 1000;
            }
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                matrix[j][n-1-i] += MAGIC*(matrix[i][j]%MAGIC);
            }
        }

        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                matrix[i][j] /= MAGIC;
                matrix[i][j] -= 1000;
            }
        }

    }
};




int main() {
    std::cout << "Hello, World!" << std::endl;
    cout << INT32_MAX;
    return 0;
}
