#include <iostream>
#include <vector>
using namespace std;

vector<int> path;

int indexOfZero(vector<int>& arr){
    for(int i=0; i<arr.size(); ++i){
        if(arr[i]==0){
            return i;
        }
    }
    return -1;
}

bool checkMovable(vector<int>& arr){
    int index = indexOfZero(arr);
    if(index>=0){
        if(index-1>=0){
            if(arr[index-1]<=3) {
                return true;
            }
        }
        if(index+1<=6 && arr[index+1>=4]){
            return true;
        }
        return false;
    }
    return false;
}

bool checkCorrect(vector<int>& arr){
    for(int i=0; i<3; ++i){
        if(!(arr[i]>=1 && arr[1])){}
    }

}


void dfs(){


}


int main() {
    std::cout << "Hello, World!" << std::endl;

    vector<int> arr  ={1,2,3,0,4,5,6};


    return 0;
}
