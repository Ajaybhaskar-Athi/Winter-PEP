#include <bits/stdc++.h>
using namespace std;

// Memoisation: O(sum*k)

// int maxLenSubsetSumToK(int n, int k, vector<int> &v)
// {
//     // Write your code here.
//     vector<vector<int>> dp(n, vector<int>(k + 1, -1));
//     return helper(0, k, v, dp);
// }


int helper(int idx, int k, vector<int> &v, vector<vector<int>> &dp)
{
    int n = v.size();
    if (k == 0)
        return 0;
    if (k < 0 || idx >= n)
        return INT_MIN;
    if (dp[idx][k] != -1)
        return dp[idx][k];

    int taken = 1 + helper(idx + 1, k - v[idx], v, dp);
    int notTaken = helper(idx + 1, k, v, dp);
    return dp[idx][k] = max(taken, notTaken);
}

//Tabulation
// int maxLenSubsetSumToK(int n, int k, vector<int> &v)
// {
//     // Write your code here.
//     vector<vector<int>> dp(n+1, vector<int>(k + 2, 0));
//     for(int i=1;i<=k+1;i++)dp[n][i]=INT_MIN;
//     for(int i=0;i<=n;i++)dp[i][0]=INT_MIN;
//     for(int i=n-1;i>=0;i--){
//         for(int j=0;j<=k;j++){
//             int taken=1+dp[i+1][j-v[i]+1];
//             int notTake=dp[i+1][j+1];
//             dp[i][j+1]=max(taken,notTake);
//         }
//     }

//     return dp[0][1];
// }




int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    // cout << maxLenSubsetSumToK(n, k, v);
}
