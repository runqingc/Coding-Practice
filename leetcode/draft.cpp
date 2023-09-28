#include<iostream>
#include<vector>
using namespace std;

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
            // cout << median_arr[i] << endl;
        }
        return median_of_five(median_arr);
    }

    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        // cout << "n=" << n << endl;
        int mid = median(nums);
        // cout << "mid=" << mid << ", k="<< k <<endl;
        
        int i, count_r=0, find_mid = 0;
        vector<int> L; vector<int> R;
        /*partition*/
        for(i=0; i<n; i++){
            if(nums[i]==mid && find_mid==0){
                find_mid = 1;
                continue;
            }
            if(nums[i]<mid){
                L.push_back(nums[i]); 
            }else if(nums[i]>=mid){
                R.push_back(nums[i]); count_r++; 
            }
        }
        // cout << count_r << endl;
        if(count_r + 1==k) return mid;
        if(count_r + 1 < k){
            return findKthLargest(L, k-count_r-1);
        }else{
            return findKthLargest(R, k);
        } 


        
    }

int main(){
    
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    cout << findKthLargest(nums, 4);

    


    return 0;

}

