#include<bits/stdc++.h>
using namespace std;

//Sliding Window

/*
- sliding one array over another
- TC= O(m*n) 
*/
class Solution {
public:
    int helper(vector<int>&nums1,vector<int>&nums2){
        int maxLen=0;
        for(int shift=0;shift<nums1.size();shift++){
            int len=0;
            for(int i=0;i<nums2.size() && i+shift<nums1.size();i++){
                if(nums1[i+shift]==nums2[i]){
                    len++;
                    maxLen=max(len,maxLen);
                }
                else 
                    len=0;
            }
        }
        return maxLen;
    }

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        return max(helper(nums1,nums2),helper(nums2,nums1));
    }
};



//Dynamic Programming

//1. Recursion

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int maxLen=0;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                maxLen=max(maxLen,helper(nums1,nums2,i,j,0));
            }
        }
        return maxLen;
    }

    int helper(vector<int>& nums1, vector<int>& nums2,int i,int j,int len){
        if(i>=nums1.size() || j>=nums2.size())
                                    return len;
         if(nums1[i]==nums2[j]){
            return helper(nums1,nums2,i+1,j+1,len+1);
         }
         else return len;
    }

};


//Memoisation

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int maxLen=0;
        vector<vector<int>>dp(nums1.size(),vector<int>(nums2.size(),-1));
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++){
                maxLen=max(maxLen,helper(nums1,nums2,i,j,0,dp));
            }
        }
        return maxLen;
    }

    int helper(vector<int>& nums1, vector<int>& nums2,int i,int j,int len,vector<vector<int>>&dp){
        if(i>=nums1.size() || j>=nums2.size())
                                    return  0;
         if(dp[i][j]!=-1)return dp[i][j];
         if(nums1[i]==nums2[j]){
            return dp[i][j]=helper(nums1,nums2,i+1,j+1,len+1,dp);
         }
         else return dp[i][j]= 0;
    }

};




//Tabulation 
//tc=O(m*n)

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int maxLen=0;
        vector<vector<int>>dp(nums1.size()+1,vector<int>(nums2.size()+1,0));
        for(int i=nums1.size()-1;i>=0;i--){
            for(int j=nums2.size()-1;j>=0;j--){
                if(nums1[i]==nums2[j]){
                    dp[i][j]=dp[i+1][j+1]+1;
                     maxLen = max(maxLen, dp[i][j]);
                }else{
                    dp[i][j]=0;//no match so reset the length
                }
            }
        }
        return maxLen;
    }


};
