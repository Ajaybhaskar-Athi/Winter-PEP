#include <bits/stdc++.h>
using namespace std;

//means in our target substring each char's frequency must be greater or equal than k.

//BruteForce


class Solution {
public:
    bool isValid(unordered_map<char,int>&mp,int k){
        for(auto pair:mp){
            if(pair.second<k)return false;
        }
        return true;
    }
    int longestSubstring(string s, int k) {
        int ans=0,n=s.size();
        for(int i=0;i<n;i++){
            unordered_map<char,int>mp;
            for(int j=i;j<n;j++){
                 mp[s[j]]++;
                 if(isValid(mp,k)){
                    ans=max(ans,j-i+1);
                 }
            }
        }
        return ans;
    }
};

//TC=o(n**3);




//Sliding window 
/*
We iterate up to maxUnique because we are checking substrings where 1 unique character repeats at least k times,
 then 2 unique characters repeat at least k times, and so on, calculating their lengths.*/

//we r finding susbtring with uniqchar=1 that was repeating atleast k times and Repeating this upto uniqChar=maxUniqCount in the string

class Solution {
public:
    int longestSubstring(string s, int k) {
     int maxUnique = unordered_set<char>(s.begin(), s.end()).size();
     int n=s.size(),ans=0;
     for(int uniqCount=1;uniqCount<=maxUnique;uniqCount++){
        int l=0,r=0,countAtLeastK=0,uniqChar=0;
        unordered_map<char,int>mp;
        while(r<n){
            if(mp[s[r]]==0)uniqChar++;
            mp[s[r]]++;
            if(mp[s[r]]==k)countAtLeastK++;

            while(uniqChar>uniqCount){
                if(mp[s[l]]==k)countAtLeastK--;
                mp[s[l]]--;
                if(mp[s[l]]==0)uniqChar--;
                l++;
            }
            if(uniqChar==uniqCount && uniqChar==countAtLeastK){
                ans=max(ans,r-l+1);
            }
            r++;

        }
     }
     return ans;
    }
};
