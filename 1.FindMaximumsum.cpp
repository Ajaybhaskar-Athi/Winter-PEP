// find max sum of subarray of size k

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumSumSubarray(vector<int> &arr, int k)
    {
        // code here
        int left = 0, right = 0;
        int n = arr.size();
        int sum = 0, ans = INT_MIN;
        while (right < n)
        {
            if (right - left >= k)
            {
                sum -= arr[left];
                left++;
            }
            sum += arr[right];
            ans = max(ans, sum);
            right++;
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    cin >> k;
    int result = sol.maximumSumSubarray(arr, k);
    cout << result;

    return 0;
}
