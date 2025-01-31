#include<bits/stdc++.h>
using namespace std;

//Memoisation

class Solution {
  public:
    int helper(int idx,int prevIdx,vector<int>&arr,vector<vector<int>>&dp){
        int n=arr.size();
        if(idx>=n)return 0;
        if(dp[idx][prevIdx+1]!=-1)return dp[idx][prevIdx+1];
        int notTake=helper(idx+1,prevIdx,arr,dp);
        int match=0;
        if(prevIdx==-1 || arr[idx]>arr[prevIdx]){
            match=1+helper(idx+1,idx,arr,dp);
        }
    
        return dp[idx][prevIdx+1]= max(notTake,match);
    }
    
    int lis(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1)); //taking prev=-1 as prev=0 i.e,, 1 based indexing and its last value is last 2nd element only thats why n+1
        return helper(0,-1,arr,dp);
    }
};




//Tabulation:

int lis(vector<int>& arr) {
    int n = arr.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0)); // Resize for safety

    for (int idx = n - 1; idx >= 0; idx--) {
        for (int prev = idx - 1; prev >= -1; prev--) {
            // Not take the current element
            int notTake = dp[idx + 1][prev + 1];
            
            // Take the current element if valid
            int take = 0;
            if (prev == -1 || arr[idx] > arr[prev]) {
                take = 1 + dp[idx + 1][idx + 1];
            }
            
            dp[idx][prev + 1] = max(notTake, take);
        }
    }

    return dp[0][0];
}

