#include<bits/stdc++.h>
using namespace std;
/*
Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.

 

Example 1:

Input: nums = [1,4,3,2]
Output: 4
Explanation: All possible pairings (ignoring the ordering of elements) are:
1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
So the maximum possible sum is 4.
Example 2:

Input: nums = [6,2,6,5,1,2]
Output: 9
Explanation: The optimal pairing is (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9.


Input : nums=[0,-1]
output: -1 




*/


class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
         int n=nums.size(),k=*max_element(nums.begin(),nums.end());
         int mini=*min_element(nums.begin(),nums.end());
         int shift=mini<0 ? -mini:0;
        vector<int>countArr(k+shift+1,0);
        for(int ele:nums)countArr[ele+shift]++;
        int ans=0;
        bool pick=true;
 //count Array having count of elemnts in sorted . min(a,a+x) is always a only . so instead of doing min op^n directly add a and skip a+x
        for(int i=0;i<countArr.size();i++ ){
            while(countArr[i]>0 ){
                if(pick)ans+=(i-shift);//shift back to original 
                pick=!pick;
                countArr[i]--;
            }
        }
        return ans;
    }
};





