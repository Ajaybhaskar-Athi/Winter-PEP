#include<bits/stdc++.h>
using namespace std;



//Memoisation : O(n^3) and sc=O(n+n)
//But due to over redundant calls on plaindrome cheking its give Memory Limit Exceeded Error 
class Solution {
public:
    bool checkPalindrome(string sr) {
        int i = 0, j = sr.size() - 1;
        while (i < j) {
            if (sr[i] != sr[j])
                return false;
            i++;
            j--;
        }
        return true;
    }

    int helper(int idx,  string s,vector<int>&dp) {
        int n = s.size();
        if (idx == n)
            return 0;
        if(dp[idx]!=-1)return dp[idx];
        string temp ="";
        int minCost = INT_MAX;
        for (int j = idx; j < n; j++) {
            temp+=s[j]; //or simply s.substr(idx,j) instead of this temp variable
            if (checkPalindrome(temp)) {
               int cost = 1 + helper(j+ 1, s,dp);
                minCost=min(minCost,cost);
            }
        }
        return dp[idx]= minCost;
    }

    int minCut(string s) { 
        vector<int>dp(s.size(),-1);
        return helper(0, s,dp)-1; 
        }
};


//Making dp for  plaindrome checking TC=O(n^2)



//Memoisation : 

class Solution {
public:
    vector<vector<int>>memo;
    bool checkPalindrome(int i,int j,string sr) {
        if(i>=j) return true;
       if(memo[i][j]!=-1)return memo[i][j];
        if(sr[i]==sr[j]) return memo[i][j]= checkPalindrome(i+1,j-1,sr);
        else return memo[i][j]= false;
    }

    int helper(int idx,  string s,vector<int>&dp) {
        int n = s.size();
        if (idx == n)
            return 0;
        if(dp[idx]!=-1)return dp[idx];
        string temp ="";
        int minCost = INT_MAX;
        for (int j = idx; j < n; j++) {
            temp+=s[j]; //or simply s.substr(idx,j) instead of this temp variable
            if (checkPalindrome(idx,j,s)) {
               int cost = 1 + helper(j+ 1, s,dp);
                minCost=min(minCost,cost);
            }
        }
        return dp[idx]= minCost;
    }

    int minCut(string s) { 
        memo.assign(s.size(),vector<int>(s.size(),-1));
        vector<int>dp(s.size(),-1);
        return helper(0, s,dp)-1; 
        }
};




//But still You get TLE Error , then  do Tabulation
//you can do Tabaulation for Plaindrom echecking also for further optimisation



class Solution {
public:
    vector<vector<int>> memo;

    bool checkPalindrome(int i, int j, string &s) {
        if (i >= j) return true;
        if (memo[i][j] != -1) return memo[i][j];
        if (s[i] == s[j]) return memo[i][j] = checkPalindrome(i + 1, j - 1, s);
        else return memo[i][j] = false;
    }

    int minCut(string s) {
        int n = s.size();
        memo.assign(n, vector<int>(n, -1));
        for(int )

        vector<int> dp(n + 1, 0);  // dp[i] will be the minimum cuts for substring s[0...i-1]
        for (int i = n - 1; i >= 0; i--) {
            int minCost = INT_MAX;
            for (int j = i; j < n; j++) {
                if (checkPalindrome(i, j, s)) {
                    int cost = 1 + dp[j + 1];
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }

        return dp[0] - 1;  // Subtract 1 because we start with 0 cuts
    }
};
