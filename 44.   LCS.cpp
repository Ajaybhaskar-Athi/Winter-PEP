#include<bits/stdc++.h>
using namespace std;

//Recursion: O(2^n) SC=O(n);

class Solution {
public:
    int helper(int i,int j,string s1,string s2){
            if(i<0 || j<0)return 0;

        int match=0;
        if(s1[i]==s2[j]){
            match=1+helper(i-1,j-1,s1,s2);
        }
        int notMatch=max(helper(i-1,j,s1,s2),helper(i-1,j,s1,s2));
        return max(match,notMatch);

    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size(),n2=text2.size();
        return helper(n1-1,n2-1,text1,text2);
    }
};



//Memoisation: O(n1*n2) sc=O(n*m)


class Solution {
public:
    int helper(int i,int j,string s1,string s2,vector<vector<int>>&dp){
            if(i<0 || j<0)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]= 1+helper(i-1,j-1,s1,s2,dp);
        }
        return dp[i][j]= max(helper(i,j-1,s1,s2,dp),helper(i-1,j,s1,s2,dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size(),n2=text2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return helper(n1-1,n2-1,text1,text2,dp);
    }
};



//Tabulation: 


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

