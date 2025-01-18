#include <bits/stdc++.h>
using namespace std;

// BruteForce
class Solution
{
public:
    int longestUniqueSubstr(string &s)
    {
        // code here
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_map<int, int> mp;
            for (int j = i; j < n; j++)
            {

                if (mp.find(s[j]) != mp.end())
                {
                    break;
                }
                mp[s[j]]++;
                ans = std::max(ans, static_cast<int>(mp.size()));
            }
        }
        return ans;
    }
};

// BruteFroce With Set

class Solution
{
public:
    int longestUniqueSubstr(string &s)
    {
        // code here
        int n = s.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            unordered_set<int> st;
            for (int j = i; j < n; j++)
            {

                if (st.find(s[j]) != st.end())
                {
                    break;
                }
                st.insert(s[j]);
                int tmp = st.size(); // convertinng size_t to int datatype
                ans = max(ans, tmp);
                // ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};

// Sliding Window

class Solution
{
public:
    int longestUniqueSubstr(string &s)
    {
        // code here
        int n = s.size(), ans = 0;
        int l = 0, r = 0;
        unordered_set<int> st;
        while (r < n)
        {
            while (st.find(s[r]) != st.end() && l < r) // o(2n)
            {
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};
