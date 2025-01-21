#include<bits/stdc++.h>
using namespace std;

//TC= O(n),sc=O(n)
class Solution{
public:	
    void solver(int n,int extraOnes,string sr,vector<string>&ans){
        
        if(n==0){
            ans.push_back(sr);
            return;
        }
        solver(n-1,extraOnes+1,sr+"1",ans);
        if(extraOnes>0){
            solver(n-1,extraOnes-1,sr+"0",ans);
        }
        
    }

	vector<string> NBitBinary(int n)
	{
	    // Your code goes here
	    vector<string>ans;
	    solver(n,0,"",ans);
	    return ans;
	}
};


