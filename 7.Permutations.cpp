// You are given a string s and a pattern p.
// You need to find all starting indices of permutations of p in the string s.

// A permutation means that the substring in s should contain all characters of p with the same frequency, but the order can be different.

/*
Input:
s = "cbaebabacd"
p = "abc"

Output: [0, 6]

Explanation:

"cba" (indices 0-2) is a permutation of "abc".
"bac" (indices 6-8) is a permutation of "abc".
Both substrings contain all characters of "abc" in any order.

*/

#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> sMap, vector<int> pMap)
{
    for (int i = 0; i < 26; i++)
        if (sMap[i] < pMap[i])
            return false;
    return true;
}

vector<int> permutations(string s, string p)
{
    vector<int> sMap(26, 0), pMap(26, 0);
    vector<int> indices;
    for (int i = 0; i < p.size(); i++)
        pMap[p[i]-'a']++;

    int l = 0, r = 0;
    while (r < s.size())
    {
        sMap[s[r]-'a']++;
        if (r - l + 1 > p.size())
            sMap[s[l++]-'a']--;
        if (compare(sMap, pMap))
            indices.push_back(l);
        r++;
    }
    return indices;
}


int main(){
    string s,p;
    cin>>s>>p;
    vector<int>v=permutations(s,p);
    for(int ele:v)cout<<ele<<" ";
}