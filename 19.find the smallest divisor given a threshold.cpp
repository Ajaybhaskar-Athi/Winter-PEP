#include<bits/stdc++.h>
using namespace std;


//BruteForce

class Solution {
  public:
    int smallestDivisor(vector<int>& arr, int k) {
        //lowest divisor=1 and highest divisor=max Element of array
        
        int low=1,high=*max_element(arr.begin(),arr.end());
        int n=arr.size();
       for(int i=low;i<=high;i++){
            int sum=0;
           for(int ele:arr){
               sum+=(ele+i-1)/i;
           }
           if(sum<=k){
               return i;
           }
       }
       return -1;
    }
};

//TC=O(MaxEle*n);

//Binary Search
class Solution {
  public:
    int smallestDivisor(vector<int>& arr, int k) {
        //lowest divisor=1 and highest divisor=max Element of array
        int low=1,high=*max_element(arr.begin(),arr.end());
        int n=arr.size(),ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int sum=0;
            for(int ele:arr){
                sum+=(ele+mid-1)/mid;//manual cieling function
            }
            if(sum<=k){
                ans=mid;
                high=mid-1;//go and search for lowest divisor then this
            }
            else low=mid+1;
        }
        return ans;
    }
};

//TC=O(n log(maxEle));
