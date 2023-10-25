#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
    vector<vector<int>> prefix;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        prefix = matrix;
        for(int i=0; i<matrix.size(); ++i){
            for(int j=0; j< matrix[0].size(); ++j){
                if(i){
                    prefix[i][j] += prefix[i-1][j];
                }
                if(j){
                    prefix[i][j] += prefix[i][j-1];
                }
                if(i && j){
                    prefix[i][j] -= prefix[i-1][j-1];
                }
            }
        }

    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = prefix[row2][col2];
        if(row1){
            sum -= prefix[row1-1][col2];
        }
        if(col1){
            sum -= prefix[row2][col1-1];
        }
        if(row1 && col1){
            sum += prefix[row1-1][col1-1];
        }
        return sum;
    }
};




int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
