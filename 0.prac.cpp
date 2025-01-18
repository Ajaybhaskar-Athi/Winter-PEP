#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    string ans="";
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        if(a==1)ans="HARD";
    }
    if(ans=="")cout<<"EASY";
    else cout<<ans;
}