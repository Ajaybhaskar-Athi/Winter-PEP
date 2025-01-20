#include<bits/stdc++.h>
using namespace std;


//BruteForce : 

class Solution {
public:
    int countPartitions(vector<int> &a, int maxSum) {
    int n = a.size(); //size of array.
    int partitions = 1;
    long long subarraySum = 0;
    for (int i = 0; i < n; i++) {
        if (subarraySum + a[i] <= maxSum) {
            //insert element to current subarray
            subarraySum += a[i];
        }
        else {
            //insert element to next subarray
            partitions++;
            subarraySum = a[i];
        }
    }
    return partitions;
}



    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();
        if (k > n)
            return -1;

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        for (int i = low; i <= high; i++) {
            if (countPartitions(arr, i) == k) {
                return i;
            }
        }
        return low;
    }

}
;


//Binary Search



class Solution {
public:
    int countPartitions(vector<int>& a, int maxSum) {
        int n = a.size(); // size of array.
        int partitions = 1;
        long long subarraySum = 0;
        for (int i = 0; i < n; i++) {
            if (subarraySum + a[i] <= maxSum) {
                // insert element to current subarray
                subarraySum += a[i];
            } else {
                // insert element to next subarray
                partitions++;
                subarraySum = a[i];
            }
        }
        return partitions;
    }

    int splitArray(vector<int>& arr, int k) {
        int n = arr.size();
        if (k > n)
            return -1;

        int low = *max_element(arr.begin(), arr.end());//
        int high = accumulate(arr.begin(), arr.end(), 0); //maxAllowedSum

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int partitions = countPartitions(arr, mid);

            if (partitions > k) {
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return low;
    }
};
