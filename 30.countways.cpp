

//The code you provided calculates the number of ways to completely fill a 4×n matrix using 4×1 matrices.

/*

The Key Idea:
A 1×4 matrix takes up one row and four columns.
A 4×1 matrix takes up one column and four rows.

So, for a given matrix of size  4×n, you have two options for placing the smaller matrices:
Place a  1×4 matrix horizontally, which will take up 1 row and 4 columns. This means you have to subtract 4 from 𝑛
1×4 matrix, reducing the available width).
Place a 4×1 matrix vertically, which will take up 1 column and 4 rows. This means you have to subtract 1 from n 4×1 matrix, reducing the available width by 1).
Recursive Relation:

*/
#include <iostream>
using namespace std;

int countWays(int n) {
if(n<=3)return 1;

    return countWays(n - 4) + countWays(n - 1);
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    cout << "Number of ways to fill a 4x" << n << " matrix: " << countWays(n) << endl;
    return 0;
}
