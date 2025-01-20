#include<bits/stdc++.h>
using namespace std;



//Binary Search : searching boques made for each day starting from minArr to maxArr

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(m*k<bloomDay.size())return -1;
        int minDayReq = *min_element(bloomDay.begin(), bloomDay.end());
        int maxDayReq = *max_element(bloomDay.begin(), bloomDay.end());
        int l = minDayReq, r = maxDayReq;
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2; // day choosed
            int totalBoquetsMade = boquesPerDay(bloomDay, m, k, mid);
            if (totalBoquetsMade >= m) {
                ans=mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }

    int boquesPerDay(vector<int>& v, int m, int k, int day) {
        int consFlowers = 0, totalBoques = 0;
        for (int flower : v) {
            if (flower <= day)
                consFlowers++;
            else 
                consFlowers = 0;
        
            if(consFlowers==k){
                totalBoques++;
                consFlowers=0;
            }
            

        }
        return totalBoques;
    }
};