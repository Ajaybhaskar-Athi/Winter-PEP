#include<bits/stdc++.h>
using namespace std;



void countStrings(int n,string sr,int prev){
    if(n==0){
        cout<<sr<<endl;
        return;
    }
    countStrings(n-1,sr+"0",0);
    if(prev==0){
        countStrings(n-1,sr+"1",1);
    }
}


int main(){
    int n=3;
    countStrings(n,"",0);
}