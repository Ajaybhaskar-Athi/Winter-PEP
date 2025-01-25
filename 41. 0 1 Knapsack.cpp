#include<bits/stdc++.h>
using namespace std;

/*
A thief wants to rob a store. He is carrying a bag of capacity W. 
The store has ‘n’ items. Its weight is given by the ‘wt’ array and its value by the ‘val’ array.
 He can either include an item in its knapsack or exclude it but can’t partially have it as a fraction. 
 We need to find the maximum value of items that the thief can steal.
*/

//Recursion: O(2^n) SC=O(n);
class Solution {
  public:
    int helper(int idx, int capacity, vector<int> &wt, vector<int> &val)
    {
        if (capacity == 0 || idx == val.size())
            return 0;
        if (idx > val.size())
            return INT_MIN;

        int take = INT_MIN;
        if (capacity - wt[idx] >= 0)
            take = val[idx] + helper(idx+1, capacity - wt[idx], wt, val);
        int notTake = helper(idx + 1, capacity, wt, val);

        return max(take, notTake);
    }
  
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
            int n = wt.size();
        return helper(0, capacity, wt, val);   
    }
};


//Memoisation
//TC=O(n*m) and SC=O(n*m)


class Solution {
  public:
    int helper(int idx, int capacity, vector<int> &wt, vector<int> &val, vector<vector<int>>&dp)
    {
        if (capacity == 0 || idx == val.size())
            return 0;
        if (idx > val.size())
            return INT_MIN;
        if(dp[idx][capacity]!=-1)return dp[idx][capacity];
        int take = INT_MIN;
        if (capacity - wt[idx] >= 0)
            take = val[idx] + helper(idx+1, capacity - wt[idx], wt, val,dp);
        int notTake = helper(idx + 1, capacity, wt, val,dp);

        return dp[idx][capacity]= max(take, notTake);
    }
  
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
            int n = wt.size();
            vector<vector<int>>dp(n,vector<int>(capacity+1,-1));
        return helper(0, capacity, wt, val,dp);   
    }
};