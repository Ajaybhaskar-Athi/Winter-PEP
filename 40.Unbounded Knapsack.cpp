/*

A thief wants to rob a store. He is carrying a bag of capacity W. The store has ‘n’ items of infinite supply.
 Its weight is given by the ‘wt’ array and its value by the ‘val’ array. He can either include an item in
 its knapsack or exclude it but can’t partially have it as a fraction.
  We need to find the maximum value of items that the thief can steal.
  He can take a single item any number of times he wants and put it in his knapsack.

  EX: N=3,W=10
  wt=[2,4,6] and val=[5,11,13]
  Output: 27  (the thief can put the items in following way: 2 items of weight 4 and 1 item of weight 2)
*/

#include <bits/stdc++.h>
using namespace std;

// Recursion :O(2^n) SC=O(n)(recursive stack space)

class Solution
{
public:
    int helper(int idx, int capacity, vector<int> &wt, vector<int> &val)
    {
        if (capacity == 0 || idx == val.size())
            return 0;
        if (idx > val.size())
            return INT_MIN;

        int take = INT_MIN;
        if (capacity - wt[idx] >= 0)
            take = val[idx] + helper(idx, capacity - wt[idx], wt, val);
        int notTake = helper(idx + 1, capacity, wt, val);

        return max(take, notTake);
    }

    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        // code here
        int n = wt.size();
        return helper(0, capacity, wt, val);
    }
};

// with below iterative Recursion ,we can stop recursion to till end when weight we found was greater then capacity

// Memoisation TC=O(n*w) and SC=O(n*w+n)
/*
in this if suppose i make profit variable instead of adding to recursive one then in memoisation also u need to make another vector for
profit too like 3d Array bcoz the profit parameter is changing
thats why add it to the Recursove call instead of passing it as profit+val[idx]
*/

class Solution
{
public:
    int helper(int idx, int capacity, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp)
    {
        if (capacity == 0 || idx == val.size())
            return 0;
        if (idx > val.size())
            return INT_MIN;
        if (dp[idx][capacity] != -1)
            return dp[idx][capacity];

        int take = INT_MIN;
        if (capacity - wt[idx] >= 0)
            take = val[idx] + helper(idx, capacity - wt[idx], wt, val, dp);
        int notTake = helper(idx + 1, capacity, wt, val, dp);

        return dp[idx][capacity] = max(take, notTake);
    }

    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        // code here
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        return helper(0, capacity, wt, val, dp);
    }
};

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- 

// In above Recursion there are two variables (capcity,index) that are changing . BUT if we traverse through weights Array
//  instead of index then we just need 1D array in memoisation
// and with this you will get ultimate Space optimisation(better then tabualtion)  approach easily

// Recursion

// Time complexity: O(N^C); //bcoz whenver it faces wt>capacity it doesnt do recursion its just do iteration. so unnecesary recursions Decreases
// Space complexity: O(C) //bcoz of recursion stack

class Solution
{
public:
    int helper(int capacity, vector<int> &wt, vector<int> &val)
    {
        if (capacity == 0)
            return 0;

        int maxProfit = 0;
        for (int idx = 0; idx < wt.size(); idx++)
        {
            if (capacity >= wt[idx])
            {
                int ans = val[idx] + helper(capacity - wt[idx], wt, val);
                maxProfit = max(maxProfit, ans);
            }
        }
        return maxProfit;
    }

    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        // code here
        int n = wt.size();
        return helper(capacity, wt, val);
    }
};

// Memoisation:

// TC=O(n*w) and SC=O(n+n);

class Solution
{
public:
    int helper(int capacity, vector<int> &wt, vector<int> &val, vector<int> &dp)
    {
        if (capacity == 0)
            return 0;
        if (dp[capacity] != -1)
            return dp[capacity];
        int maxProfit = 0;
        for (int idx = 0; idx < wt.size(); idx++)
        {
            if (capacity >= wt[idx])
            {
                int ans = val[idx] + helper(capacity - wt[idx], wt, val, dp);
                maxProfit = max(maxProfit, ans);
            }
        }
        return dp[capacity] = maxProfit;
    }

    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        // code here
        vector<int> dp(capacity + 1, -1);
        int n = wt.size();
        return helper(capacity, wt, val, dp);
    }
};

// Tabulation: in this if we do tabulation then its only our earlier Space optmisation one


 

  class Solution
{
public:
    int knapSack(vector<int> &val, vector<int> &wt, int capacity)
    {
        // Initialize the DP array
        vector<int> dp(capacity + 1, 0); // All entries set to 0
        int n = wt.size();

        // Iterative DP approach
        for (int idx = 0; idx < n; idx++)
        {
            for (int cap = wt[idx]; cap <= capacity; cap++)
            {
                int include = val[idx] + dp[cap - wt[idx]];
                dp[cap] = max(dp[cap], include);
            }
        }
        return dp[capacity];
    }
};

