#include<bits/stdc++.h>
using namespace std;


//Recursion : O(n.2^n) => o(n) is to pushing elements into curr vector and 2^n is to genrate all subsets .
// space complexity=O(2^n)+O(n)=> 2^n is to store subsets and n is for recursions stack

class Solution {
public:
    void helper(int idx,vector<int>&curr,vector<int>&nums,vector<vector<int>>&ans){
        int n=nums.size();
        if(idx==n){
            ans.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        helper(idx+1,curr,nums,ans);
        curr.pop_back();        
        helper(idx+1,curr,nums,ans);

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        helper(0,curr,nums,ans);
        return ans;
    }
};


//using bit manipulation :
// Time Complexity: O(n.2^n)
// Auxiliary Space: O(1)

class Solution{
	public:
		vector<string> AllPossibleStrings(string s){
		    vector<string>ans;
		    int n=s.size();
		    for(int i=0;i<(1<<n);i++){ //o to 2^(n-1) subsets
		           string sub=""; 
		           for(int j=0;j<n;j++){ //iterate through that bit string
		               if(i & (1<<j)) sub+=s[j]; //add if bit is set
		           }
		           ans.push_back(sub);
		    }
		    // sort(ans.begin(),ans.end());  //sort if they asked in lexicographical order
		    return ans;
		    
		}
};

