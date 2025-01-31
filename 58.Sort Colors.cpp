#include<bits/stdc++.h>
using namespace std;


//TC=O(n+n)=O(n)

class Solution {
public:
    void sortColors(vector<int>& nums) {
            int zeroes=0, ones=0,twos=0;
            for(int ele:nums){
                if(ele==0)zeroes++;
                else if(ele==1)ones++;
                else twos++;
            }
            int i=0;
            while(zeroes>0){
                nums[i++]=0;
                zeroes--;
            }
            while(ones>0){
                nums[i++]=1;
                ones--;
            }
            while(twos>0){
                nums[i++]=2;
                twos--;
            }
            
    }
};
