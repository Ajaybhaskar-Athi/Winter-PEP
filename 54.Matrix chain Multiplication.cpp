#include<bits/stdc++.h>
using namespace std;

//Partition DP
/*
Time Complexity: O(N*N*N)

Reason: There are N*N states and we explicitly run a loop inside the function which will run for N times, therefore at max ‘N*N*N’ new problems will be solved.

Space Complexity: O(N) :Recursion stack space

*/

//Recursion : 


class Solution {
  public:
    
    int helper(int i,int j,vector<int>&arr){
        if(i==j)return 0;
        int mini=INT_MAX;
        for(int k=i;k<j;k++){
            int steps=helper(i,k,arr)+helper(k+1,j,arr)+arr[i-1]*arr[k]*arr[j] ;
            mini=min(mini,steps);
        }
        return mini;
    }
  
    int matrixMultiplication(vector<int> &arr) {
        // code here
        return helper(1,arr.size()-1,arr);
    }
};




//MEmoisation :O(N^3) 
// O(N*N) + O(N)
// Reason: We are using an auxiliary recursion stack space(O(N))and a 2D array ( O(N*N)).



class Solution {
  public:
    
    int helper(int i,int j,vector<int>&arr, vector<vector<int>>&dp){
        if(i==j)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int mini=INT_MAX;
        
        for(int k=i;k<j;k++){
            int steps=helper(i,k,arr,dp)+helper(k+1,j,arr,dp)+arr[i-1]*arr[k]*arr[j] ;
            mini=min(mini,steps);
        }
        return dp[i][j]= mini;
    }
  
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        return helper(1,arr.size()-1,arr,dp);
    }
};



//Tabulation


