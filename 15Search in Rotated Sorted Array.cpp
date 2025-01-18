#include<bits/stdc++.h>
using namespace std;

//Linear Search =O(n)

int search(vector<int>& arr, int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;
    }
    return -1;
}


//Binary Search =O(nlogn)
/*
As the Array is Rotated Try to find which part is sorted by comparing mid with low & high.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)/2;
             if(nums[mid]==target)return mid;
             
            if(nums[low]<=nums[mid]){ //left half is sorted
                 if(nums[low]<=target && target<=nums[mid]) high=mid-1;
                 else low=mid+1;
            }
            else{//right half is sorted
                 if(nums[mid]<=target && target<=nums[high] ) low=mid+1;
                else high=mid-1;
            }                      
        }
        return -1;
    }
};


