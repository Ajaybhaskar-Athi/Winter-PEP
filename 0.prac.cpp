#include <iostream>
using namespace std;

long long numberOfBinaryStrings(int n) {
    if (n == 0) return 1;  // Base case: dp(0)
    if (n == 1) return 2;  // Base case: dp(1)
    
    // Fibonacci-like recurrence relation
    return numberOfBinaryStrings(n-1) + numberOfBinaryStrings(n-2);
}

int main() {
    int n;
    cin >> n;
    cout << numberOfBinaryStrings(n) << endl;
    return 0;
}
