#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string s1, string s2) {
    int n1 = s1.size(), n2 = s2.size();
    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0)); 

    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n2; j++) {
            if (s1[i - 1] == s2[j - 1])  
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else 
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
    }

    int i = n1, j = n2;
    string res = "";
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            res += s1[i - 1];
            i--;
            j--;
        } else {
            if (dp[i - 1][j] > dp[i][j - 1])
                i--;
            else
                j--;
        }
    }
    reverse(res.begin(), res.end()); // Reverse the result string

    cout  << res << endl;
    return dp[n1][n2];
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    longestCommonSubsequence(s1, s2);
    return 0;
}
