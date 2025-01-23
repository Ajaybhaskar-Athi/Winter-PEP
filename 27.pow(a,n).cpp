#include<bits/stdc++.h>
using namespace std;


/*//Recursive Naive Method: TC= O(n) SC=O(n) due to recursiev stack

long long powNaive(long long a, long long n) {
    if (n == 0) return 1; // Base case
    return a * powNaive(a, n - 1); // Recursive case
}



//Iterative Naive Method  : O(n) Sc =O(1) 
long long powNaive(long long a, long long n) {
    if (n == 0) return 1; // Base case
    return a * powNaive(a, n - 1); // Recursive case
}
*/




//Recursive O(logn)



int powRec(int a,int n){
    if(n==0)return 1;
    int res=pow(a,n/2);
    if(n&1) return a*res*res; //if odd
    return res*res; //if even
}

int main() {
    int a, n;
    cin >> a >> n;
    cout << pow(a, n) << endl;
    return 0;
}



/*
Leetcode problem: negative expoenential handling
class Solution {
public:
    double helper(double a, long n) {
        if (n == 0)
            return 1;
        double res = helper(a, n / 2);
        if (n % 2 != 0)
            return a * res * res; // odd exponent
        return res * res;         // even exponent
    }

    double myPow(double a, int n) {
        // Use long to handle edge cases like n = INT_MIN
        long exponent = n;
        if (exponent < 0) {
            a = 1 / a;
            exponent = -exponent; // Make the exponent positive
        }
        return helper(a, exponent);
    }
};



When n is INT_MIN, negating it will cause an overflow. By converting it to long, you avoid this issue.
*/