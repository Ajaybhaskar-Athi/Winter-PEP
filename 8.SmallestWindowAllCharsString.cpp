#include <bits/stdc++.h>
using namespace std;

// BruteForce

class Solution
{
public:
    int findSubString(string &s)
    {
        unordered_set<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++)
            st.insert(s[i]);
        int ans = INT_MAX;
        ;
        for (int i = 0; i < n; i++)
        {
            unordered_map<char, int> mp;
            for (int j = i; j < n; j++)
            {
                mp[s[j]]++;
                if (mp.size() == st.size())
                {
                    ans = min(ans, j - i + 1);
                    break;
                }
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};

// SLIDING window

class Solution
{
public:
    int findSubString(string &s)
    {
        unordered_set<char> st;
        int n = s.size();
        for (int i = 0; i < n; i++)
            st.insert(s[i]);
        int ans = INT_MAX;
        unordered_map<char, int> mp;
        int l = 0, r = 0;
        while (r < n)
        {
            mp[s[r]]++;
            while (mp.size() == st.size() )
            {
                ans = min(ans, r - l + 1);
                mp[s[l++]]--;
            }
            r++;
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};
