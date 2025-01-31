#include<bits/stdc++.h>
using namespace std;

/*
It is a sweltering summer day, and a boy wants to buy some ice cream bars.

At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 

Note: The boy can buy the ice cream bars in any order.

Return the maximum number of ice cream bars the boy can buy with coins coins.

You must solve the problem by counting sort.

 

Example 1:

Input: costs = [1,3,2,4,1], coins = 7
Output: 4
Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.


Topics: Sorting 

*/

//TC=O(max+n)
//SC=o(n+max)

//You simply done sorting and then process the 
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size(),k=*max_element(costs.begin(),costs.end());
        vector<int>countArr(k+1);
        for(int ele:costs)countArr[ele]++;
        for(int i=1;i<=k;i++){
            countArr[i]+=countArr[i-1];
        }
        vector<int>temp(n); //sortedArray
        for(int i=n-1;i>=0;i--){
            temp[--countArr[costs[i]]]=costs[i];
        }
        int ans=0;
        int i=0;
        while(i<n && temp[i]<=coins){
            ans++;
            coins-=temp[i++];
        }
        return ans;
    }
};


//Actually you dont need sorting too , bcoz you r having  countArr which is already in sorted .so you can directly buy the icecreams instead of stroing the countArr again in tempArr
//TC=O(max+n)
//Sc=O(max)
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size(),k=*max_element(costs.begin(),costs.end());
        vector<int>countArr(k+1,0);
        for(int ele:costs)countArr[ele]++;
        int ans=0;
        for(int i=0;i<=k;i++ ){
            while(countArr[i]>0 && coins>=i){
                coins-=i;
                countArr[i]--;
                ans++;
            }
        }
        return ans;
    }

};
