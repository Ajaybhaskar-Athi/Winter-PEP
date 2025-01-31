#include<bits/stdc++.h>
using namespace std;
/*

Given an array arr[] containing n positive integers, a subsequence of nums is called bitonic if it is first strictly increasing, then strictly decreasing. The task is to find the length of the longest bitonic subsequence. 
Note: A strictly increasing or a strictly decreasing sequence should not be considered as a bitonic sequence.

Examples:

Input: arr[]= [12, 11, 40, 5, 3, 1]
Output: 5 
Explanation: The Longest Bitonic Subsequence is {12, 40, 5, 3, 1} which is of length 5.


Input: arr[] = [80, 60, 30]
Output: 0
Explanation: There is no possible Bitonic Subsequence.

*/

//Recursion:  TC=O(n.2^n) and sc=O(n)

class Solution {
  public:
  
    int leftDec(int idx,int prev,vector<int>&arr){
        if(idx<0)return 0;
        int notTake=leftDec(idx-1,prev,arr);
        int match=0;
        if(arr[idx]<arr[prev])match=1+leftDec(idx-1,idx,arr);
        return max(notTake,match);
    }
  
  int rightDec(int idx,int prev,vector<int>&arr){
        if(idx>=arr.size())return 0;
        int notTake=rightDec(idx+1,prev,arr);
        int match=0;
        if(arr[idx]<arr[prev])match=1+rightDec(idx+1,idx,arr);
        return max(notTake,match);
    }
  
  
    int LongestBitonicSequence(int n, vector<int> &arr) {
        // code here
        int maxLen=0;
        for(int i=1;i<n-1;i++){
            
            int leftLen=leftDec(i-1,i,arr); //decreasing subseq to the left (which is clalled as increasing subseq from 0 to right)
            int rightLen=rightDec(i+1,i,arr);
            if(leftLen==0 || rightLen==0){//make balance if subsequnce is either strictly increasing or decreasing 
                leftLen=0; 
                rightLen=0;
            }
            maxLen=max(maxLen,leftLen+rightLen+1);
        }
        return maxLen<3 ? 0: maxLen; //for a valid Bitonic subsequnce it must increase and then decrease so atleast 3 len is required for a biotonic subsequnce
    }
};



//Memoisation: TC=O(n^3) and sc=O(n^2)


class Solution {
  public:
  
    int leftDec(int idx,int prev,vector<int>&arr,  vector<vector<int>>&leftDP){
        if(idx<0)return 0;
        if(leftDP[idx][prev]!=-1)return leftDP[idx][prev];
        int notTake=leftDec(idx-1,prev,arr,leftDP);
        int match=0;
        if(arr[idx]<arr[prev])match=1+leftDec(idx-1,idx,arr,leftDP);
        return leftDP[idx][prev]= max(notTake,match);
    }
  
  int rightDec(int idx,int prev,vector<int>&arr,vector<vector<int>>&rightDP){
        if(idx>=arr.size())return 0;
        if(rightDP[idx][prev]!=-1)return rightDP[idx][prev];
        int notTake=rightDec(idx+1,prev,arr,rightDP);
        int match=0;
        if(arr[idx]<arr[prev])match=1+rightDec(idx+1,idx,arr,rightDP);
        return rightDP[idx][prev]= max(notTake,match);
    }
  
  
    int LongestBitonicSequence(int n, vector<int> &arr) {
        // code here
        vector<vector<int>>leftDP(n,vector<int>(n,-1));
        vector<vector<int>>rightDP(n,vector<int>(n,-1));
        int maxLen=0;
        for(int i=1;i<n-1;i++){
            
            int leftLen=leftDec(i-1,i,arr,leftDP); //decreasing subseq to the left (which is clalled as increasing subseq from 0 to right)
            int rightLen=rightDec(i+1,i,arr,rightDP);
            if(leftLen==0 || rightLen==0){//make balance if subsequnce is either strictly increasing or decreasing 
                leftLen=0; 
                rightLen=0;
            }
            maxLen=max(maxLen,leftLen+rightLen+1);
        }
        return maxLen<3 ? 0: maxLen;
    }
};


//