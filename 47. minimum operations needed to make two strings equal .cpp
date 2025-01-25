/*
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string.

 

Example 1:

Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
Example 2:
*/

#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:

    int minDistance(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        int len=longestCommonSubsequence(s1,s2);
        int deletions=n-len;
        int insertions=m-len;
        return insertions+deletions;    
    }



      int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,-1));
        for(int i=0;i<=n1;i++)dp[i][0]=0;
        for(int j=0;j<=n2;j++)dp[0][j]=0;

        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(s1[i-1]==s2[j-1])dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=0+max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return dp[n1][n2];
    }
 
};



