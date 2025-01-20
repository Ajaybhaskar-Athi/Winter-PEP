#include<bits/stdc++.h>
using namespace std;


//Recursion


class Solution {
  public:
    int countFriendsPairings(int n) {
        // code here
        if(n<=2)return n;
        int single=countFriendsPairings(n-1);
        int pair=(n-1)*countFriendsPairings(n-2); //current can pair with any n-1 friends & find ways fro remaining n-2 friends
        return single+pair;
    }
};




//DP Memoisation

class Solution {
  public:
    int helper(int n,vector<int>&dp){
        if(n<=2)return n;
        if(dp[n]!=-1)return dp[n];
        int single=helper(n-1,dp);
        int pair=(n-1)*helper(n-2,dp); //current can pair with any n-1 friends & find ways fro remaining n-2 friends
        return dp[n]=single+pair;
    }
    int countFriendsPairings(int n) {
       vector<int>dp(n+1,-1);//dp[i] is the number of ways to arrange i friends as single or paired.
       return helper(n,dp);
    }
};


