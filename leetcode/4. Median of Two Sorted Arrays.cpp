#include<vector>
#include<iostream>
using namespace std;

    

    /*find smallest: k=0*/
    double findkthsmall(vector<int>& nums1, vector<int>& nums2, int k){
        
        
        int m = nums1.size(); int n = nums2.size();
        // int new_m = m, new_n = n, new_k = k;
        int offset1 = 0; int offset2 = 0;
        int pivot1, pivot2, index1, index2;

        while(1){
            
            /*when an array is empty or k==0*/
            if(m==0) return nums2[k + offset2];
            if(n==0) return nums1[k + offset1];
            if(k==0) return min(nums1[offset1], nums2[offset2]);
            if(k==1) {
                if(nums1[offset1]< nums2[offset2]){
                    offset1++; m--;
                }else{
                    offset2++; n--;
                }
                k--; continue;
            }

            /*if nums[offset1 + k/2] is not a valid index, pick the last element as pivot*/
            /*inde is the number of elements being delete*/
            if(offset1 + k/2 -1 <= m-1) {pivot1 = nums1[offset1 + k/2 -1]; index1 = k/2-1;}
            else {pivot1 = nums1[m-1]; index1 = m-1;}
            if(offset2 + k/2-1 <= n-1) {pivot2 = nums2[offset2 + k/2 -1]; index2 = k/2-1;}
            else {pivot2 = nums2[n-1]; index2 = n-1;}
                
            /*delete impossible elements*/
            cout << "k=" << k << endl;
            cout << "index = " << index1 << endl;
            cout << "offset1 = " << offset1 << endl;
            cout << "pivot1 = " << pivot1 << endl;
            cout << "pivot2 = " << pivot2 << endl;
            if(pivot1 <= pivot2){
                offset1 = offset1 + index1 + 1;
                k = k - index1 - 1;
                m = m - index1 - 1;
            }else if(pivot2 < pivot1){
                offset2 = offset2 + index2 + 1;
                k = k - index2 - 1;
                n = n - index2 - 1;
            }
        }

    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total_size = nums1.size() + nums2.size();
        
        if(total_size%2==1){
            // cout<< "findkthsmall(nums1, nums2, total_size/2) " << findkthsmall(nums1, nums2, total_size/2) << endl;
            return findkthsmall(nums1, nums2, total_size/2);
        }else{
            cout<< "findkthsmall(nums1, nums2, total_size/2) " << findkthsmall(nums1, nums2, total_size/2) << endl;
            cout<< "findkthsmall(nums1, nums2, total_size/2-1) " << findkthsmall(nums1, nums2, total_size/2-1) << endl;
            return (findkthsmall(nums1, nums2, total_size/2) + findkthsmall(nums1, nums2, total_size/2-1))/2;
        }

    }




int main(){
    vector<int> nums1 = {2,2,4,4};
    vector<int> nums2 = {2,2,4,4};
    findMedianSortedArrays(nums1, nums2);


    return 0;
}