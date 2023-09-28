#include<vector>
#include<string>
#include<iostream>
using namespace std;


class Solution {
public:
    int median_of_five(vector<int>& nums){
        int n = nums.size(); int i, j, tmp;
        for(i=1; i<n; i++){
            tmp = nums[i];
            for(j=i-1; j>=0 && nums[j]>tmp; j--){
                nums[j+1] = nums[j];
            }
            nums[j+1] = tmp;
        }
        return nums[n/2];
    }


    int median(vector<int>& nums){
        if(nums.size()<=5){
            return median_of_five(nums);
        }
        int i; int n = nums.size();
        vector<int> median_arr;
        for(i=0; i<5; i++){
            vector<int> Arr2;
            vector<int>::const_iterator First = nums.begin() + i*(n-1)/5; 
            vector<int>::const_iterator Second = nums.begin() + (i+1)*(n-1)/5;
            Arr2.assign(First, Second);
            median_arr.push_back(median(Arr2));
        }
        return median_of_five(median_arr);
    }

    int findKthLargest(vector<int>& nums, int k) {
        int mid = median(nums);
        int n = nums.size();
        int i, count_l=0;
        vector<int> L; vector<int> R;
        /*partition*/
        for(i=0; i<n; i++){
            if(nums[i]<=mid){
                L.push_back(nums[i]); count_l++;
            }else if(nums[i]>mid){
                R.push_back(nums[i]);
            }
        }
        if(count_l==n-k) return mid;
        if(count_l>n-k){
            return findKthLargest(L, k);
        }else{
            return findKthLargest(R, n-k-count_l-1);
        } 


        
    }
};