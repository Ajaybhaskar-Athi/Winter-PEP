#include <bits/stdc++.h>
using namespace std;

//By traversing in both directions - O(n) Time and O(1) Space 

 int maxProduct(vector<int> &arr) {
        // Your Code Here
        int pre=1,suff=1,n=arr.size();
        int ans=INT_MIN;
        
        for(int i=0;i<n;i++){
            if(pre==0)pre=1;
            if(suff==0)suff=1;
            pre*=arr[i];
            suff*=arr[n-i-1];
            ans=max(ans,max(pre,suff));
        }
        return ans;
        
    }


//KADANES ALGO


//Using minimum and maximum product ending at any index - O(n) Time and O(1) Space 
//Kadanes Algorithm

/*

If we encounter zero, then all the subarrays containing this zero will have product = 0, so zero simply resets the product of the subarray.
If we encounter a negative number, we need to keep track of the 'minimum product' as well as the 'maximum product' ending at the previous index. This is because when we multiply the minimum product with a negative number, it can give us the maximum product. So, keeping track of minimum product ending at any index is important as it can lead to the maximum product on encountering a negative number.
Step-by-step algorithm:
*/


//Refer this https://www.geeksforgeeks.org/batch/gfg-160-problems/track/arrays-gfg-160/article/MjIyMTY%3D

class Solution {
  public:
    
    int maxProduct(vector<int> &arr) {
      int currMin=arr[0],currMax=arr[0],ans=arr[0];
      int n=arr.size();
      for(int i=1;i<n;i++){
        int temp=max({arr[i],currMin*arr[i],currMax*arr[i]});
        currMin=min({arr[i],currMin*arr[i],currMax*arr[i]});
        currMax=temp;
        ans=max(ans,temp);
        
      }
      return ans;
    }
};


