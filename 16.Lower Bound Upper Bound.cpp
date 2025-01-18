#include<bits/stdc++.h>
using namespace std;
//Find First and Last Position of Element in Sorted Array :O(logn)

//first find lower bound : for LB move towards left when we found target
//next upper bound: for UB go towards right when we found target

class Solution {
public:
    int lowerBound(vector<int>&arr,int target){
        int n=arr.size(),low=0,high=n-1;
        int lowerBound=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target){
                lowerBound=mid;
                high=mid-1;
            }
            else if(target<arr[mid]) high=mid-1;
            else low=mid+1;
        }
        return lowerBound;
    }

     int upperBound(vector<int>&arr,int target){
        int n=arr.size(),low=0,high=n-1;
        int upperBound=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==target){
                upperBound=mid;
                low=mid+1;
            }
            else if(target<arr[mid]) high=mid-1;
            else low=mid+1;
        }
        return upperBound;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        int lowerBnd=lowerBound(nums,target);
        int upperBnd=upperBound(nums,target);
        return {lowerBnd,upperBnd};
    }
};