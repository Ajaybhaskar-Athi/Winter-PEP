 /*Given an array/list of length ‘N’, where the array/list represents the boards and each element of the given array/list
  represents the length of each board. Some ‘K’ numbers of painters are available to paint these boards.
   Consider that each unit of a board takes 1 unit of time to paint.
    You are supposed to return the area of the minimum time to get this job done of painting all the ‘N’ boards
     under the 
     "constraint that any painter will only paint the CONTINUOUS sections of boards".*/

/*
[10,20,30,40] k=2 ( 2 painters)
Possibilities:
Painter 1: 10, 20, 30 and painter 2: 40 => time taken by painter1 t1=60 and time taken by painter2 t2=40 . task finished at =max(40,60)=60
painter 1: 10,20 and painter 2: 30,40 => t1=30 and t2=70 so task finshed at time=70
painter 1:10 and painter 2: 20,30,40 => t1=10 and t2=90 so task finsineg at time =90

min time =min(all max );
so Min time taken =60 with 1st possibiltiy

*/

#include<bits/stdc++.h>
using namespace std;



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
    
    int minTime(vector<int>& arr, int k) {
       int n = arr.size();
    

        int low = *max_element(arr.begin(), arr.end());
        int high = accumulate(arr.begin(), arr.end(), 0);

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int paritions = countPartitions(arr, mid);

            if (paritions > k) {
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return low;
    }
};



