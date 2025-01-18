#include<bits/stdc++.h>
using namespace std;


//bruteForce

class Solution {
public:
    int findMaxi(vector<int>&v){
        int maxi=INT_MIN;
        for(int ele:v)
                maxi=max(ele,maxi);
        return maxi;
    }

    int characterReplacement(string s, int k) {
        int n=s.size(),ans=0;
        for(int i=0;i<n;i++){
             vector<int>v(26,0); //all uppercase letters ,u can use Map too
             for(int j=i;j<n;j++){
                v[s[j]-'A']++;
                int charMax=findMaxi(v);
                if((j-i+1)-charMax <=k)
                    ans=max(ans,j-i+1);
                else 
                    break;
             }
        }
        return ans;
    }
};


//Slidig Window

class Solution {
public:
    int findMaxi(vector<int>&v){
        int maxi=INT_MIN;
        for(int ele:v)
                maxi=max(ele,maxi);
        return maxi;
    }

    int characterReplacement(string s, int k) {
        int n=s.size(),ans=0;
        vector<int>v(26,0); //all uppercase letters ,u can use Map too
        int l=0,r=0;
        while(r<n){
            v[s[r]-'A']++;
            int charMax=findMaxi(v);
            if((r-l+1)-charMax>k){
                v[s[l]-'A']--;
                l++;
            }
            else 
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
