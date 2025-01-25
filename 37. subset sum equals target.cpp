#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>

// Memoisation : O(target*n)

bool helper(int idx, int k, vector<int> &v, vector<vector<int>> &dp)
{
    int n = v.size();
    if (k == 0)
        return true;
    if (k < 0 || idx >= n)
        return false;
    if (dp[idx][k] != -1)
        return dp[idx][k];

    bool taken = helper(idx + 1, k - v[idx], v, dp);
    bool notTaken = helper(idx + 1, k, v, dp);

    return dp[idx][k] = (taken || notTaken);
}

bool subsetSumToK(int n, int k, vector<int> &v)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return helper(0, k, v, dp);
}

// Tabulation

#include <bits/stdc++.h>

bool helper(int idx, int k, vector<int> &v, vector<vector<int>> &dp)
{
    int n = v.size();
    if (k == 0)
        return true;
    if (k < 0 || idx >= n)
        return false;
    if (dp[idx][k] != -1)
        return dp[idx][k];
    bool taken = helper(idx + 1, k - v[idx], v, dp);
    bool notTaken = helper(idx + 1, k, v, dp);
    return dp[idx][k] = (taken || notTaken);
}

bool subsetSumToK(int n, int k, vector<int> &v)
{
    // Write your code here.
    vector<vector<bool>> dp(n + 1, vector<bool>(k + 1, false));
    for (int i=n-1;i>=0;i--){
    }
}


class Solution{
    public:
    bool helper(int k,vector<int>&nums){
            int n=nums.size();
            if(k==0)return true;
            if(k<0) return false;

            
    }
    bool subsetSumEqualsK(int k,vector<int>&arr){
        int n = arr.size();
        return helper(k,arr);
    }
}