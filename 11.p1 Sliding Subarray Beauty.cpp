#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> v;
        int n = nums.size();

        for (int i = 0; i <= n - k; i++) {
            vector<int>negatives;
            for (int j = i; j < i + k; j++) {
              if(nums[j]<0)negatives.push_back(nums[j]);
            }
            if(negatives.size()<x)v.push_back(0);
            else{
                sort(negatives.begin(),negatives.end());
                v.push_back(negatives[x-1]);
            }
        }
        return v;
    }
};



//Sliding window Method


class Solution {
public:
    int findMap(map<int,int>&mp,int x){
        int count=0;
        for(auto&ele:mp){
            count+=ele.second;
            if(count>=x)return ele.first;
        }        
        return 0;
    }

    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        vector<int> v;
        int n = nums.size();

        map<int, int> mp; // to store the -ve nos
        int l=0,r=0;
        while(r<n){
            if(nums[r]<0)mp[nums[r]]++;
            if(r-l+1>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0)mp.erase(nums[l]);
                l++;
            }
            if(r-l+1==k){
            int val=findMap(mp,x);
            v.push_back(val);
            }
            r++;
        }
       return v;
    }
};

