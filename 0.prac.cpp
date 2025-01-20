#include <bits/stdc++.h>
using namespace std;



void insertAtBottom(stack<int>&stk,int ele){
    if(stk.empty() || ele<=stk.top()){
        stk.push(ele);
        return;
    }
    int top=stk.top();
    stk.pop();
    insertAtBottom(stk,ele);
    stk.push(top);
}

void sortStack(stack<int>&stk){
    // helper(stk,stk.top());    
    if(stk.empty())return ;
    int top=stk.top();
    stk.pop();
    sortStack(stk);
    insertAtBottom(stk,top);

}

int main(){
    stack<int>stk;
    stk.push(1);
    stk.push(5);
    stk.push(2);
    stk.push(4);
    sortStack(stk);
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
    }
}