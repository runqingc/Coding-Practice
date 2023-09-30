#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int largestRectangleArea(vector<int>& heights) {
    deque<int> q;
    // the left most element >= heights[i] (index)
    vector<int> left_max(heights.size(), 0);
    vector<int> right_max(heights.size(), (int)heights.size()-1);

    for(int i=0; i<heights.size(); ++i){
        if(q.empty()){
            q.push_back(i);
        }else{
            if(!q.empty() && heights[i]<heights[q.back()]){
                while(!q.empty() && heights[q.back()]>heights[i]){
                    right_max[q.back()] = i-1;
                    q.pop_back();
                }
                if(!q.empty())left_max[i] = q.back()+1;
                q.push_back(i);
            }else if(!q.empty() && heights[i]==heights[q.back()]){
                if(!q.empty())left_max[i] = left_max[q.back()];
                q.push_back(i);
            }else{
                if(!q.empty())left_max[i] = q.back()+1;
                q.push_back(i);
            }
        }
    }

    int max_rectangle = 0;
    for(int i=0; i<heights.size(); ++i){
        int rectangle = heights[i]*(right_max[i]-left_max[i]+1);
        if(rectangle>max_rectangle){
            max_rectangle = rectangle;
        }
    }
    return max_rectangle;

}



int main() {
    vector<int> heights {2,4};
    cout << largestRectangleArea(heights);
    return 0;
}
