#include<bits/stdc++.h>
using namespace std;

/*
Linear Time Algorithm
Stable Sorting Algorithm
Non-comparison based Algorithm
Sorts elements on the basis of their digits.

Works for a bigger range unlike count sort.


TC: O(d*(n+k));// d=maxi
Count sort is often used as a subroutine in radix sort
*/

void countSort(vector<int>&arr,int maxi,int pos){
    int n=arr.size();
    vector<int>count(10,0);//digits are from 0 to 9 only
    for(int ele: arr){
        count[(ele/pos )%10]++;
    }
    for(int i=1;i<10;i++){
        count[i]+=count[i-1];
    }
    vector<int>b(n);
    for(int i=n-1;i>=0;i--){
        b[--count[(arr[i]/pos)%10]]=arr[i];
    }
    arr=b;
}


void radixSort(vector<int>&arr){
    int maxi=*max_element(arr.begin(),arr.end()); // no with max digits . no of passes(times) we don count sort is equals to no of digits in maxi
    for(int pos=1;(maxi/pos)>0 ;pos*=10){ //i=1 (ones) ,i=10(tens),i=100 (100s digit)
        countSort(arr,maxi,pos);
    }
}

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];
    redixSort(v);
    for(int ele:v)cout<<ele<<" ";
}