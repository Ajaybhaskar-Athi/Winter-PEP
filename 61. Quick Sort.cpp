#include<bits/stdc++.h>
using namespace std;


/*
quick sort is an in place sorting Algo

Quick Sort is a divide-and-conquer algorithm like the Merge Sort. 
But unlike Merge sort, this algorithm does not use any extra array for sorting(though it uses an auxiliary stack space).
 So, from that perspective, Quick sort is slightly better than Merge sort.



steps:
1. choose the pivot 
2. partition the array around the pivot
3. recursively sort the subarrays on the left and right of the pivot (all the elements left to pivot are lesser then pivot and all elemntes that are on right side are greater then pivot)




 TIME COMPLEXITY :
 worst case: o(n^2) //unbalanced partitoning
 best case: o(n log n)
 avg case :o(nlogn)

SPACE COMPELXITY:
O(log n) (Recursive stack space, in-place sorting).
*/


class Solution {
  public:

    int partition(vector<int>& arr, int low, int high) {
        
        int s=low,e=high,pivot=arr[low];
        while(s<e){
            
            while(arr[s]<=pivot)s++;
            while(arr[e]>pivot)e--;
            if(s<e)swap(arr[s],arr[e]);
        }
        swap(arr[low],arr[e]);
        return e;
    }
    
    void quickSort(vector<int>& arr, int low, int high) {
        if(low<high){
            int pivotIndex=partition(arr,low,high); //its give the index where the pivot was placed after sorting ,so now sort remaining two halves
            quickSort(arr,low,pivotIndex-1);
            quickSort(arr,pivotIndex+1,high);
        }
    }

};


