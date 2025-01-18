#include <bits/stdc++.h>
using namespace std;


//KADANES ALGO

class Solution {
  public:
    
    int maxSubarraySum(vector<int> &arr) {
       int currMax=arr[0];
       int res=arr[0];
       for(int i=1;i<arr.size();i++){
           currMax=max(currMax+arr[i],arr[i]);
           res=max(res,currMax);
       }
       return res;
    }
};


//suppose if they want us to return the subArray then Follow the STIRVER method

/*

long long maxSubarraySum(int arr[], int n) {
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;
    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {

        if (sum == 0) start = i; // starting index
        sum += arr[i];
        if (sum > maxi) {
            maxi = sum;
            ansStart = start;
            ansEnd = i;
        }
        if (sum < 0) {
            sum = 0;
        }
    }

    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]n";

    return maxi;
}

*/