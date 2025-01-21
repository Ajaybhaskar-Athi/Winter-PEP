#include<bits/stdc++.h>
using namespace std;


//Recursion

/*int solver(int prev,int n){
        if(n==0)return 0;
        if(n==1) return prev==1 ? 1: 2;

        if(prev==0)return solver(0,n-1)+solver(1,n-1);
        else return solver(0,n-1);
    }

int numberOfBinaryStrings(int n) {
    // Write your code here.
    return solver(0,n);

}*/



//Memoisation

const long long MOD = 1000000007; //also =1e9+7

vector<vector<long long>> memo;

long long solver(int prev, int n) {
    if (memo[n][prev] != -1) return memo[n][prev];
    if (n == 0) return 0;
    if (n == 1) return prev == 1 ? 1 : 2;
    if (prev == 0) {
        return memo[n][prev] = (solver(0, n-1) + solver(1, n-1)) % MOD;
    } else {
        return memo[n][prev] = solver(0, n-1) % MOD; //for large values like n=100 it may cross size of int thats why do mod 
    }
}

long long numberOfBinaryStrings(int n) {
    memo.resize(n + 1, vector<long long>(2, -1));  // n+1 rows, 2 columns
    return solver(0, n);
}



//Tabulation

long long numberOfBinaryStringss(int n){
vector<vector<long long>> dp(n+1,vector<long long>(2,0));
dp[1][0]=2;
dp[1][1]=1;
for(int i=2;i<=n;i++){
    dp[i][0]=(dp[i-1][0]+dp[i-1][1])%MOD;
    dp[i][1]=dp[i-1][0] %MOD;
}
return dp[n][0];

}




int main(){
    int n;
    cin>>n;
    cout<<numberOfBinaryStringss(n);
}


//You can also do the Fibonacci Recursion for this which solevs the same 