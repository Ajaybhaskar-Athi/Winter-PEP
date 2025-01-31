#include<bits/stdc++.h>
using namespace std;


//Memoisation - Top down Approach : o(n*m) , SC=O(n*m)+O(n+m)

class Solution {
  public:
  
    int helper(int i,int j,string s1,string s2,vector<vector<int>>&dp){
        if(i<0)return j+1;
        if(j<0)return i+1;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j]= helper(i-1,j-1,s1,s2,dp);
        int insert=1+helper(i,j-1,s1,s2,dp);
        int del=1+helper(i-1,j,s1,s2,dp);
        int replace=1+helper(i-1,j-1,s1,s2,dp);
        return dp[i][j]= min({insert,del,replace});
    }
    
  
    // Function to compute the edit distance between two strings
    int editDistance(string& s1, string& s2) {
        // code here
        int n=s1.size(),m=s2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(n-1,m-1,s1,s2,dp);
    }
};



//Tabualtion :O(n*m) and sc=O(n*m) no Resucrsion stack space


int editDistance(string& s1, string& s2) {
        // code here
        int n=s1.size(),m=s2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=m;i++)dp[0][i]=i;//not i+1 bcoz its 1 based indexing
        for(int i=0;i<=n;i++) dp[i][0]=i;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=1+min({dp[i][j-1],dp[i-1][j-1],dp[i-1][j]});
            }
        }
        return dp[n][m];
    }





