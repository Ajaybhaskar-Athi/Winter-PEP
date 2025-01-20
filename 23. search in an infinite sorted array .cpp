#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>&arr ,int low, int high, int key) {
  while (low <= high) {

    int mid = (low + high) / 2;
    if (arr[mid] < key) {
      low = mid + 1;
    } else if (arr[mid] > key) {
      high = mid - 1;
    } else {
      return mid;
    }

  }
  return -1;
}


int findIndex(vector<int>&v,int target){
    int start=0,end=1;
    //find the given target comes in which part of the array
    //instead of applying binary search in an unknown size (infinite long) array ,first trim the array

    while(target>v[end]){
        start=end+1;
        end=end*2;
    }
    return binarySearch(v,start,end,target);
}