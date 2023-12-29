#include <iostream>
#include <vector>
using namespace std;

// find the k-th largest element(a.k.a the arr[k] in the sorted array) where k = (m+n)/2 or (m+n)/2-1
// suppose it is in nums1: for i in [0, k], check if it has the valid position (binary)
// nums1[mid] should >= exactly k-mid element in nums[2]
int findKthLargest(vector<int>& nums1, vector<int>& nums2, int k){
    // special case: one of the vector is empty
    if(nums1.empty()) return nums2[k];
    if(nums2.empty()) return nums1[k];

    // search in nums1
    int l = 0; int r = min(k, (int)nums1.size()-1); int mid;
    while(l<=r){
        mid = (l+r)/2; // k-mid: the numbers that I shall beat
        if((k-mid==0 && nums1[mid]<nums2[0]) ||
            (k-mid==nums2.size() && nums1[mid]>nums2.back()) ||
            (k-mid>=1 && k-mid<=nums2.size()-1 && nums2[k-mid-1]<=nums1[mid] && nums1[mid]<=nums2[k-mid])){
            return nums1[mid];
        }else if(k-mid<0 || (k-mid>=1 && k-mid<=nums2.size()-1 && nums2[k-mid]<nums1[mid])){ // nums1[mid] is too large
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    // search in nums2
    l=0; r = min(k, (int)nums2.size()-1);
    while(l<=r){
        mid = (l+r)/2; // k-mid: the numbers that I shall beat
        if((k-mid==0 && nums2[mid]<nums1[0]) ||
           (k-mid==nums1.size() && nums2[mid]>nums1.back()) ||
           (k-mid>=1 && k-mid<=nums1.size()-1 && nums1[k-mid-1]<=nums2[mid] && nums2[mid]<=nums1[k-mid])){
            return nums2[mid];
        }else if(k-mid<0 || (k-mid>=1 && k-mid<=nums1.size()-1 && nums1[k-mid]<nums2[mid])){ // nums2[mid] is too large
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return nums1[0];
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if((nums1.size()+nums2.size())%2==1){
        return findKthLargest(nums1, nums2, (int)(nums1.size()+nums2.size())/2);
    }
    return 0.5*(findKthLargest(nums1, nums2, (int)((nums1.size()+nums2.size())/2))+
    findKthLargest(nums1, nums2, (int)((nums1.size()+nums2.size())/2-1)));
}


int main() {
    vector<int> nums1{1,2,3,4,5};
    vector<int> nums2{0,3,4,7,9,10};
    std::cout << findKthLargest(nums1, nums2, 2) << std::endl;
    cout << findMedianSortedArrays(nums1, nums2)<<endl;
    return 0;
}
// 0 1 1 2 3 4 6 6 7 8