#include <bits/stdc++.h>
using namespace std;

/*
Counting Sort is a non-comparative sorting algorithm.

It works well when sorting numbers within a small range. ( upper bound of max element= length of the array ,beyond that not prefered)
It counts occurrences of each number and places them in the correct order.

Steps to Perform Counting Sort:
Find the maximum value in the array.
Create a count array of size (max + 1), initialized with 0.
Count occurrences of each number in the input array.
Modify the count array to store cumulative counts.

Place elements in the output array based on count positions. => start from last index of array while placing in sorted order with respect to coutnarray
bcoz suppose at index=12 and 15 we have 9. if i start from index=0 then i will place value at index 12 at last position of 9 ,but it should be at 1st position of 9. even though array is sorted but for stabilty we make sure that value at index 9 will appear before value at index 15

Copy the sorted output back to the original array.


*/



//Time complexity: O(Max+n) =O():Linear Time complexity
// Suitable for values that are in small range


//below count sort is only Applicable for Positive numbers 


void countSort(vector<int> &nums)
{
    int n = nums.size(), k = *max_element(nums.begin(), nums.end());

    vector<int> countArr(k + 1, 0); //maxi+1
    for (int ele : nums)
        countArr[ele]++;
    for (int i = 1; i < countArr.size(); i++)
    {
        countArr[i] += countArr[i - 1];
    }
    vector<int> temp(n);
    for (int i = n - 1; i >= 0; i--)
    {
        temp[--countArr[nums[i]]] = nums[i]; // since countArr is having positions to before storing place it in its index and not on position
    }
    nums = temp;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    countSort(nums);
    for (int ele : nums)
        cout << ele << " ";
}



/*handle Negative elemnts too . simple we will add min negative element to tall elements of arr and do the operation

Original:  [-3, -1, -2, -5, -4]
minElement = -5
Shifted:   [ 2,  4,  3,  0,  1]   // Added 5 to each element



*/

void countSort(vector<int> &nums) {
    int minElement = *min_element(nums.begin(), nums.end());
    int maxElement = *max_element(nums.begin(), nums.end());

    int shift = (minElement < 0) ? -minElement : 0;  // Shift only if needed

    vector<int> countArr(maxElement +shift+ 1, 0);
    //otherwise add shift to each element of array and do same count sort for positive and subtract shift after sort and shift to the original arrayu
    for (int num : nums) countArr[num + shift]++;
    for (int i = 1; i < countArr.size(); i++) countArr[i] += countArr[i - 1];

    vector<int> temp(nums.size());
    
    for (int i = nums.size() - 1; i >= 0; i--) {
        temp[--countArr[nums[i] + shift]] = nums[i];  // Place elements correctly
    }

    nums = temp;  
}

int main() {
    vector<int> nums = {2, 4, 3, 5, 1};  // Already positive, no shifting needed
    countSort(nums);

    for (int ele : nums) cout << ele << " ";
    return 0;
}
