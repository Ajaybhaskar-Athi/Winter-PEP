#include<bits/stdc++.h>
using namespace std;



//Greedy :O(n^2)

class Solution {
  public:
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        int ans=0;
        for(int i=0;i<arr.size();i++){
            for(int j=i+1;j<arr.size();j++){
                if(arr[i]>arr[j])ans++;
            }
        }
        return ans;
    }
};



//O(nlogn)

class Solution {
public:
    int merge(vector<int>& nums, int low, int mid, int high) {
        int left = low, right = mid + 1, res = 0;
        vector<int> temp;
        
        // Count inversions and merge two halves
        while (left <= mid && right <= high) {
            if (nums[left] > nums[right]) {
                res += (mid - left + 1);  // All elements in the left subarray are greater than nums[right]
                temp.push_back(nums[right++]);
            } else {
                temp.push_back(nums[left++]);
            }
        }
        
        // Add remaining elements from both subarrays
        while (left <= mid) temp.push_back(nums[left++]);
        while (right <= high) temp.push_back(nums[right++]);
        
        // Copy the sorted elements back to the original array
        for (int i = low; i <= high; i++) {
            nums[i] = temp[i - low];
        }
        
        return res;
    }

    int mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) return 0;
        
        int mid = low + (high - low) / 2;
        int inv1 = mergeSort(nums, low, mid);          // Count inversions in left subarray
        int inv2 = mergeSort(nums, mid + 1, high);     // Count inversions in right subarray
        int inv3 = merge(nums, low, mid, high);        // Count inversions between left and right subarray
        
        return inv1 + inv2 + inv3;
    }

    // Function to count inversions in the array.
    int inversionCount(vector<int>& arr) {
        return mergeSort(arr, 0, arr.size() - 1);
    }
};

