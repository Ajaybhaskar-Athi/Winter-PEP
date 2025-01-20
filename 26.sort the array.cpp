#include <bits/stdc++.h>
using namespace std;

/*
with  vectors we follow the logic similar to stack sort but actually asked to do with ARR

void insertAtCorrectPosition(vector<int>& vec, int ele) {
    if (vec.empty() || ele >= vec.back()) {
        vec.push_back(ele);
        return;
    }
    int last = vec.back();
    vec.pop_back();
    insertAtCorrectPosition(vec, ele);
    vec.push_back(last);
}

void sortVector(vector<int>& vec) {
    if (vec.empty()) return;
    int last = vec.back();
    vec.pop_back();
    sortVector(vec);
    insertAtCorrectPosition(vec, last);
}

int main() {
    vector<int> vec = {1, 5, 2, 4};
    sortVector(vec);
    for (int num : vec) {
        cout << num << " ";
    }
    return 0;
}


*/


//Dont do with Merge sort even it has Recursion bcoz it follows divide and conquer . use Recursion only

//sort from last 
//means sort last one ,last two,last three, till last n

void swapMaxTillEnd(vector<int>&arr,int start){
        int end=arr.size();
        if(start>=end-1)return;

        if(arr[start]>arr[start+1]){
            swap(arr[start],arr[start+1]);
            swapMaxTillEnd(arr,start+1);
        }
        // else return;
}


void  sort(vector<int>&arr,int n){
    if(n<=1) return;
    swapMaxTillEnd(arr,n-1);
    sort(arr,n-1);
}


int main(){
    vector<int> arr = {1, 5, 2, 4};
    sort(arr,arr.size());
    for (int num : arr) {
        cout<<num<<" ";
    }
}