#include<bits/stdc++.h>
using namespace std;


  int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0)); //1 based indexing

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
               if(s1[i-1]==s2[j-1])  dp[i][j]=dp[i-1][j-1]+1;
               else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[n1][n2];


    }


int longestPalindromicSubsequence(string s1){
    string s2=s1;
    reverse(s1.begin(),s2.begin());
    return longestCommonSubsequence(s1,s2);
}