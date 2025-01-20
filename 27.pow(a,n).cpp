#include<bits/stdc++.h>
using namespace std;


//Iterative  : O(log n)

int pow(int a, int n) {
    int res = 1;
    while (n > 0) {
        if (n & 1) res *= a; // Multiply res by a if the current bit of n is 1
        n = n >> 1;          // Right shift n (divide by 2)
        a *= a;              // Square the base
    }
    return res;
}



//Recursive O(logn)

/*

*/

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
