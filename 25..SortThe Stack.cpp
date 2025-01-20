#include<bits/stdc++.h>
using namespace std;
//sort in Descending order:(top of stack should be greater elemennt)

//with Space 
// we r making temp stack as lower as top elemnet and poping it ,copy to  original stack 
void Sort(stack<int>&stk){
    
    stack<int> temp;
    while(!stk.empty()){
        int curr=stk.top(); 
        stk.pop();
        while(!temp.empty() && temp.top()<curr){
            stk.push(temp.top());
            temp.pop();
        }
        temp.push(curr);
    }
    while(!temp.empty()){
        stk.push(temp.top());
        temp.pop();
    }
}


//without SPace: with Recursion

class solution{
    public:
    void InsertInOrder(stack<int>&stk,int ele){
        if(stk.empty() || stk.top()<=ele){
            stk.push(ele);
            return ;
        }
        int temp=stk.top();
        stk.pop();
        InsertInOrder(stk,ele);
        stk.push(temp);
    }

    void sort(stack<int>&stk){
        if(stk.empty())return;
        int top=stk.top();
        stk.pop();
        sort(stk);
        InsertInOrder(stk,top);

    }
};


int main(){
    
     int n;
    cin>>n;
    stack<int>stk;
    while(n--){
        int a;
        cin>>a;
        stk.push(a);
    }
solution obj;
obj.sort(stk);
while(!stk.empty()){
    cout<<stk.top()<<" ";
    stk.pop();
}
}