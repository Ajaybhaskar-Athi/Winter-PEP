#include <bits/stdc++.h>
using namespace std;

//o(log n)


vector<vector<int>> getIdentityMat(int sz){
    vector<vector<int>> ans(sz,vector<int>(sz,0));
    for(int i=0;i<sz;i++){
        ans[i][i]=1;
    }
    return ans;
}
vector<vector<int>> matrixMul(const vector<vector<int>>& fm, const vector<vector<int>>& sm, int n) {
    vector<vector<int>> res(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                res[i][j] += fm[i][k] * sm[k][j];
            }
        }
    }
    return res;
}

vector<vector<int>> matrixExponential(vector<vector<int>>&recMat,int n){
    if(n==0)return getIdentityMat(recMat.size());
    if(n==1)return recMat;
    vector<vector<int>>res=getIdentityMat(recMat.size());

    while(n>0){
        if(n&1){ //odd =(n%2==0)
            res=matrixMul(res,recMat,recMat.size());
        }
        recMat=matrixMul(recMat,recMat,recMat.size());
        n>>=1;//n=n/2;
    }
    return res;

}

int fib(int n) {
    // if (n == 0) return 0;
    // if (n == 1) return 1; handled in matrixExponential function

    vector<vector<int>> recMat = {{1, 1}, {1, 0}}; // Transformation matrix - Recurrence relation
    vector<vector<int>> result = matrixExponential(recMat, n - 1);
    // for(int i=0;i<2;i++){
    //     for(int j=0;j<2;j++){
    //         cout<<result[i][j]<<" ";
    //     }cout<<endl;
    // }
    
    return result[0][0]; // F(n) is located at the top-left element
}

int main()
{
    int n;
    cin >> n;
  cout<<fib(n);
   
}
