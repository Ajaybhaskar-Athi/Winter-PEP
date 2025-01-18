#include <bits/stdc++.h>
using namespace std;
// Longest Substring with At Most K Distinct Characters
// substring subarray=> solved in SLIDING WINDOW


//BruteForce

int kDistinctChars(int k, string &str) {
    int n = str.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        unordered_set<char> st;         
         for (int j = i; j < n; j++) {
            st.insert(str[j]);
            if (st.size() > k) break;
            ans = max(ans, j - i + 1);
        }
    }
    return ans;
}




//Sliding window 
int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    unordered_map<char, int> mp;
    int l = 0, r = 0, n = s.size();
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
    while(mp.size()>k){
            mp[s[l]]--;
            if(mp[s[l]]==0)mp.erase(s[l]);
            l++;
        }
        ans=max(ans,r-l+1);
        r++;
    }
    cout<<ans<<endl;
}




//BEtter Approach

int main()
{
    string s;
    cin >> s;
    int k;
    cin >> k;
    unordered_map<char, int> mp;
    int l = 0, r = 0, n = s.size();
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        mp[s[i]]++;
    if(mp.size()>k){
            mp[s[l]]--;
            if(mp[s[l]]==0)mp.erase(s[l]);
            l++;
        }
       if(mp.size()<=k) ans=max(ans,r-l+1);
        r++;
    }
    cout<<ans<<endl;
}

