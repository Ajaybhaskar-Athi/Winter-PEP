#include<bits/stdc++.h>
using namespace std;

//TC=O(logn);


class Solution {
public:
    int mySqrt(int x) {
        int low = 0, high = x - 1;
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (mid * mid == x)
                return mid;
            else if (x < mid * mid)
                high = mid - 1;
            else
                low = mid + 1;
        }
        long long sqr=(long )low*low;
        return sqr > x ? low - 1 : low;
        //Also  return sqr == x ? low  : low-1;
    }
};




