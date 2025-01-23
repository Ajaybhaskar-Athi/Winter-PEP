#include<bits/stdc++.h>
using namespace std;

//Recursion : O(2^n);

//Memoisation: O(m*n) , sc=O(m*n)+O(m+n) [2d vector +recursion stack space]

class Solution {
public:
int helper(int i,int j,int row,int col,vector<vector<int>>&dp){
        if(i==row-1 && j==col-1) return 1;
        if(i>=row || j>=col) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int right=helper(i,j+1,row,col,dp);
        int down=helper(i+1,j,row,col,dp);
        return dp[i][j]= right+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
           return helper(0,0,m,n,dp);
    }
};



//Tabualtion : O(m*n) and sc=O(n*m) : here no recursion stack space

 int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[m-1][n-1] = 1;
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if(i==m-1 && j==n-1)continue;
                dp[i][j] += dp[i + 1][j];
                dp[i][j] += dp[i][j + 1];
            }
        }

        return dp[0][0];
    }


int main(){
    Solution obj;
    int m,n;
    cin>>m>>n;
    cout<<obj.uniquePaths(m,n);
}


