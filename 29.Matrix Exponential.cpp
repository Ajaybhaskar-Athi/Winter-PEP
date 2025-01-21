#include<bits/stdc++.h>
using namespace std;

//Solving the linear Recurrance Relations


int* get(int*arr,int rowSize,int i,int j){
    return (arr+i*rowSize*j);
}

int* matrixMul(int*fm,int*sm,int n){
    int*res=new int[n*n]; //single continuos block 

    for(int i=0;i<n;i++){ //going row by row
        for(int j=0;j<n;j++){ //going column wise
        int sum=0;
            for(int k=0;k<n;k++){
                sum+=(*get(fm,n,i,k))*(*get(sm,n,k,j));
            }   
        *get(res,n,i,j)=sum;
        }
    }
    return res;
}

int getInitialMatrix(){
    int *in=new int[16]; //4*4 matrix 
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            *get(in,4,i,j)=0;
        }
    }
    *get(in,4,0,0)=29;
    *get(in,4,0,1)=11;
    *get(in,4,0,2)=100;
    *get(in,4,0,3)=26;
    *get(in,4,1,0)=1;
    *get(in,4,2,1)=1;
    *get(in,4,3,3)=1;

}


int getIdentityMatrix(){
    int *in=new int[16];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int toSet=i==j?1:0;
            *get(in,4,i,j)=toSet;
        }
    }
    // return *
}

int maxtrixPow(int*matrix,int pow){
int *res=getIdentityMatrix();
while(pow){
    if(pow & 1){
        res*=
    }
}
}

int f(n){
    if(n==0)return 2;
    if(n==1)return 1;
    if(n==2)return 1;
    int *N=getInitialMatrix();
    maxtrixPow(N,n-2);
}




/*
#include <bits/stdc++.h>
using namespace std;

int* get(int* arr, int rowSize, int i, int j) {
    return (arr + i * rowSize + j);
}

int* matrixMul(int* fm, int* sm, int n) {
    int* res = new int[n * n]; // single continuous block

    for (int i = 0; i < n; i++) { // going row by row
        for (int j = 0; j < n; j++) { // going column-wise
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += (*get(fm, n, i, k)) * (*get(sm, n, k, j));
            }
            *get(res, n, i, j) = sum;
        }
    }
    return res;
}

int* getInitialMatrix() {
    int* in = new int[16]; // 4x4 matrix stored in a single block
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            *get(in, 4, i, j) = 0; // initialize all elements to 0
        }
    }
    // Transformation matrix values
    *get(in, 4, 0, 0) = 29;
    *get(in, 4, 0, 1) = 11;
    *get(in, 4, 0, 2) = 100;
    *get(in, 4, 0, 3) = 26;
    *get(in, 4, 1, 0) = 1;
    *get(in, 4, 2, 1) = 1;
    *get(in, 4, 3, 3) = 1;

    return in;
}

int* getIdentityMatrix() {
    int* in = new int[16]; // 4x4 identity matrix
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int toSet = i == j ? 1 : 0; // diagonal elements are 1, others are 0
            *get(in, 4, i, j) = toSet;
        }
    }
    return in;
}

int* matrixPow(int* matrix, int pow, int n) {
    int* res = getIdentityMatrix(); // start with the identity matrix
    while (pow) {
        if (pow & 1) {
            res = matrixMul(res, matrix, n); // multiply if power is odd
        }
        matrix = matrixMul(matrix, matrix, n); // square the matrix
        pow >>= 1; // divide power by 2
    }
    return res;
}

int f(int n) {
    if (n == 0) return 2; // base cases
    if (n == 1) return 1;
    if (n == 2) return 1;

    int* N = getInitialMatrix(); // get transformation matrix
    int* resultMatrix = matrixPow(N, n - 2, 4); // raise it to the (n-2)th power

    int* initialVector = new int[4]{1, 1, 2, 0}; // [F(2), F(1), F(0), extra]
    int result = 0;

    // Multiply resultMatrix with initialVector to compute F(n)
    for (int i = 0; i < 4; i++) {
        result += (*get(resultMatrix, 4, 0, i)) * initialVector[i];
    }

    return result; // return the nth term
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "F(" << n << ") = " << f(n) << endl;
    return 0;
}



*/



//Without pointers


#include <iostream>
#include <vector>
using namespace std;

// Function to multiply two matrices
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

// Function to get the initial transformation matrix
vector<vector<int>> getInitialMatrix() {
    vector<vector<int>> in(4, vector<int>(4, 0));

    // Fill the matrix with the given values
    in[0][0] = 29;
    in[0][1] = 11;
    in[0][2] = 100;
    in[0][3] = 26;
    in[1][0] = 1;
    in[2][1] = 1;
    in[3][3] = 1;

    return in;
}

// Function to get the identity matrix
vector<vector<int>> getIdentityMatrix() {
    vector<vector<int>> in(4, vector<int>(4, 0));

    // Set diagonal elements to 1
    for (int i = 0; i < 4; i++) {
        in[i][i] = 1;
    }

    return in;
}

// Function to perform matrix exponentiation
vector<vector<int>> matrixPow(vector<vector<int>> matrix, int pow, int n) {
    vector<vector<int>> res = getIdentityMatrix(); // Start with the identity matrix

    while (pow) {
        if (pow & 1) {
            res = matrixMul(res, matrix, n); // Multiply if power is odd
        }
        matrix = matrixMul(matrix, matrix, n); // Square the matrix
        pow >>= 1; // Divide power by 2
    }

    return res;
}

// Function to calculate the nth term
int f(int n) {
    if (n == 0) return 2; // Base cases
    if (n == 1) return 1;
    if (n == 2) return 1;

    // Get the transformation matrix
    vector<vector<int>> N = getInitialMatrix();
    // Calculate N^(n-2)
    vector<vector<int>> resultMatrix = matrixPow(N, n - 2, 4);

    // Initial vector [F(2), F(1), F(0), extra]
    vector<int> initialVector = {1, 1, 2, 0};
    int result = 0;

    // Multiply resultMatrix with initialVector to compute F(n)
    for (int i = 0; i < 4; i++) {
        result += resultMatrix[0][i] * initialVector[i];
    }

    return result; // Return the nth term
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "F(" << n << ") = " << f(n) << endl;
    return 0;
}
