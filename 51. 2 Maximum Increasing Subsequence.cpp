#include<bits/stdc++.h>
using namespace std;

//Recursion: O(2^n)
class Solution {
  public:
    int helper(int idx,int prev,vector<int>&arr){
        int n=arr.size();
        if(idx==n)return 0;
        int notTake=helper(idx+1,prev,arr);
        int match=0;
        if(prev==-1 || arr[idx]>arr[prev]){
            match=arr[idx]+helper(idx+1,idx,arr);
        }
        
        return max(notTake,match);
        
    }
  
    int maxSumIS(vector<int>& arr) {
        // Your code goes here
        return helper(0,-1,arr);
    }
};


//Memoisation



class Solution {
  public:
    int helper(int idx,int prev,vector<int>&arr, vector<vector<int>>&dp){
        int n=arr.size();
        if(idx==n)return 0;
        if(dp[idx][prev+1]!=-1)return dp[idx][prev+1];
        int notTake=helper(idx+1,prev,arr,dp);
        int match=0;
        if(prev==-1 || arr[idx]>arr[prev]){
            match=arr[idx]+helper(idx+1,idx,arr,dp);
        }
        
        return dp[idx][prev+1]= max(notTake,match);
        
    }
  
    int maxSumIS(vector<int>& arr) {
        // Your code goes here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return helper(0,-1,arr,dp);
    }
};



