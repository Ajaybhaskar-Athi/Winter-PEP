#include<bits/stdc++.h>
using namespace std;
class Solution {
public:

    void solve(int idx,string curr,string digit,vector<string>&mp,vector<string>&ans){
            if(idx>=digit.length()) {
                ans.push_back(curr);
                return;
            }
            int num=digit[idx]-'0';
            string value=mp[num];
            for(int i=0;i<value.size();i++){
                curr.push_back(value[i]);
                solve(idx+1,curr,digit,mp,ans);
                curr.pop_back();
            }

    }

    vector<string> letterCombinations(string digits) {
            if(digits.size()==0)return {};
           vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
            vector<string>ans;
            int idx=0;
            solve(idx,"",digits,mp,ans);
            return ans;
    }
};



/*
Time complexity= O(4^n); //since it given max digit string length=4 and in worst case we get O(4^n);
Theres no any  repeated sub problems ,so no need of memoisation and all
*/