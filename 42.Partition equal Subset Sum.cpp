#include<bits/stdc++.h>
using namespace std;


/*
We are given an array ‘ARR’ with N positive integers.
 We need to find if we can partition the array into two subsets such that the sum of elements of each subset is 
 equal to the other.

If we can partition, return true else return false.*/

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

bool isPartition(vector<int>&v){
    int sum=accumulate(v.begin(),v.end(),0);
    if(sum&1) return false;//if sum is odd then theres no way to divide that sum into two equal parts
    //if even find if sum/2 is exists as subset in the array. if it exists the sum can be divide into two equal parts
    return subsetSumToK(v.size(),sum/2,v);
}