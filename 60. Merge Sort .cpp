#include<bits/stdc++.h>
using namespace std;



/*
 
Time complexities:

Best and avg case: O(nLogn) //logn for dividing into two halves and O(n) for merging them at each step
worst case :O(n logn )

Space complexites:
O(n)  {" n is for Temp vector and   `logn` is for Recusion stack space called for each dividing into half"}


Unlike QuickSort, Merge Sort is not in-place, as it requires additional memory for merging.

*/
class Solution {
public:
    void merge(vector<int>&nums,int low,int mid,int high){
        int left=low,right=mid+1;
        vector<int>temp;
        while(left<=mid &&right<=high ){
            if(nums[left]<nums[right]){
                temp.push_back(nums[left++]);
            }
            else{
                temp.push_back(nums[right++]);
            }
        }
        while(left<=mid)temp.push_back(nums[left++]);
        while(right<=high)temp.push_back(nums[right++]);
        for(int i=low;i<=high;i++){
            nums[i]=temp[i-low];
        }
    }

    void mergeSort(vector<int>&nums,int low,int high){
        if(low>=high) return;
        int mid=low+(high-low)/2;
        mergeSort(nums,low,mid);
        mergeSort(nums,mid+1,high);
        merge(nums,low,mid,high);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums,0,nums.size()-1);
        return nums;
    }
};

