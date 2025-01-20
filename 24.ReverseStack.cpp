#include<bits/stdc++.h>
using namespace std;
//Refer is u didnt understand Recusrion version https://www.geeksforgeeks.org/reverse-a-stack-using-recursion/
/*
Input:
St = {3,2,1,7,6}
Output:
{6,7,1,2,3}
Explanation:
Input stack after reversing will look like the stack in the output.

*/
//with space

/*
void reverse(stack<int>&stk){
    vector<int>v;
    while(!stk.empty()){
        v.push_back(stk.top());
        stk.pop();
    }
    for(int ele:v)stk.push(ele);
}

*/

//without space

class Solution{
public:
    
    void InsertAtBottom(stack<int>&stk,int ele){
        if(stk.empty()){
            stk.push(ele);
            return;
        }
        int temp=stk.top();
        stk.pop();
        InsertAtBottom(stk,ele);
        stk.push(temp);
    }

    void Reverse(stack<int> &St){
        if(St.empty()){
            return;
        }
        int top=St.top(); St.pop();
        Reverse(St);
        InsertAtBottom(St,top);
    }
};


int main(){

//ip=4 3 2 1 so elements of stakc from top to botoom are 1 2 3 4
    int n;
    cin>>n;
    stack<int>stk;
    while(n--){
        int a;
        cin>>a;
        stk.push(a);
    }
Solution obj;
obj.Reverse(stk);
while(!stk.empty()){
    cout<<stk.top()<<" ";
    stk.pop();
}
  

}