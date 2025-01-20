#include<bits/stdc++.h>
using namespace std;
//Return true if we found target in an array that may contain duplicates

//Search in Rotated Sorted Array -I logic is not worked here bcoz here array contains Duplicates

/*
suppose arr=[3,1,2,3,3,3,3] here mid=7/2=3 index 
acc to our logic if arr[low]<=arr[mid ]then left half is sorted otherwise right one is sorted

But here arr[0]<=arr[3] => 3<=3 satisfied but actually its not sorted   
program will give left one is sorted but actually right is sorted 

the array also might thid 
arr=[3,3,3,3,1,2,3] we dont know whcih half is sorted



PROBLEM HERe ARISES if arr[low]=arr[mid]=arr[high] then only we couldn't identify the Sorted one


*/



/*
arr=[3,3,3,3,1,2,3]
 here arr[low]=arr[mid]=arr[high] we coudlnt identify which half is sorted 
so here trim the Array as low++ and high-- as we already checked the mid with target before this so no issue
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target)return true;
            //if low,mid,high same then trim
             if(nums[low]==nums[mid]&& nums[mid]==nums[high]){
                low++;
                high--;
                continue;
            }
             if(nums[low]<=nums[mid]){
                
                if(nums[low]<=target && target< nums[mid])
                            high=mid-1;
                else low=mid+1;
            }
            else{
                if(nums[mid]<target && target<= nums[high])
                        low=mid+1;
                else high=mid-1;
            }
        }
        return false;
    }
};