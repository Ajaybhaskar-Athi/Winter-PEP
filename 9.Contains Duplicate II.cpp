#include<bits/stdc++.h>
using namespace std;


/*
Given an integer array nums and an integer k, return true if there are two distinct indices i and j 
in the array such that nums[i] == nums[j] and abs(i - j) <= k.
Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true*/

//Sliding window 
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
         int l=0,r=0,n=nums.size();
         unordered_set<int>st;
         while(r<n){
            if(st.find(nums[r])!=st.end())return true;
            st.insert(nums[r]);
            if(st.size()>k){
                st.erase(nums[l++]);
            }
            r++;
         }
         return false;
    }
};
