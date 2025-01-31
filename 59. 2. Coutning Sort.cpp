#include <bits/stdc++.h>
using namespace std;


/*
Given a string arr consisting of lowercase english letters, arrange all its letters in lexicographical order using Counting Sort.

Example 1:

Input:
N = 5
S = "edsab"
Output:
abdes
Explanation: 
In lexicographical order, string will be 
abdes.
*/
class Solution
{
public:
    string countSort(string arr)
    {
        int n = arr.size();
        vector<int> countArr(26, 0);
        for (int i = 0; i < n; i++)
            countArr[arr[i] - 'a']++;
        for (int i = 1; i < countArr.size(); i++)
        {
            countArr[i] += countArr[i - 1];
        }
        vector<char> temp(n);
        for (int i = n - 1; i >= 0; i--)
        {
            temp[--countArr[arr[i] - 'a']] = arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            arr[i] = temp[i];
        }
        return arr;
    }
};
