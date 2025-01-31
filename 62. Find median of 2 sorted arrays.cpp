#include<bits/stdc++.h>
using namespace std;



//BruteForce :O(m+n), Space Complexity:O(n)


class Solution {
public:

    void merge(vector<int>&nums1,vector<int>&nums2,vector<int>&nums3){
        int l=0,r=0;
        while(l<nums1.size() && r<nums2.size()){
            if(nums1[l]<nums2[r]){
                nums3.push_back(nums1[l++]);
            }
            else nums3.push_back(nums2[r++]);
        }
        while(l<nums1.size())nums3.push_back(nums1[l++]);
        while(r<nums2.size())nums3.push_back(nums2[r++]);

    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>nums3;
        merge(nums1,nums2,nums3);
        for(int ele:nums3)cout<<ele<<" ";
        int n=nums3.size();
        int mid=n/2;
        double ans=0.0;
        if(n%2==0){
            ans=(nums3[mid]+nums3[mid-1])/2.0;
        }
        else ans=nums3[mid];
        return ans;

    }
};


//Binary Search O(log(n)) where n=minimum size of 2 arrays


class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
         int n1=a.size();
         int n2=b.size();
         if(n1>n2)return findMedianSortedArrays(b,a);//we are applying binary search on short array te reduce time complexity
        int left=(n1+n2+1)/2; 
        int n=n1+n2;
        int low=0,high=n1;
        while(low<=high){
            int mid1=low+(high-low)/2;
            int mid2=left-mid1;
            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX,r2=INT_MAX;
            if(mid1<n1)r1=a[mid1];
            if(mid2<n2) r2=b[mid2];
            if(mid1-1>=0) l1=a[mid1-1];
            if(mid2-1>=0)l2=b[mid2-1];
            if(l1<=r2 && l2<=r1){
                if(n%2==1)return max(l1,l2);
                else return  (double)(max(l1,l2)+min(r1,r2))/2.0;
            }
            else if(l1>r2) high=mid1-1;
            else low=mid1+1;
        }
        return 0.0;

    }
};
