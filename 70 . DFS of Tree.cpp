#include<bits/stdc++.h>
using namespace std;


//DFS is Depth First Search : Postorder,preorder,inorder  ( explores as far as possible along each branch before backtracking.)
//BFS is Breadth First Search  :  nodes level by level before moving deeper. (Uses QUEUE: FIFO Algo)

//given a Edge list and convert it into Adjacency LIST



//Here in tree traversal theres no need of Visited Vector because A tree is an acyclic connected graph, meaning there's only one unique path between any two nodes.
void dfs(int parent,int startNode,vector<int>&ans,vector<vector<int>>&adj){
    ans.push_back(startNode);//pre order
    for(auto nbr:adj[startNode]){
        if(nbr==parent)continue;
        dfs(startNode,nbr,ans,adj);
    }
    // ans.push_back(startNode);//post order

}

vector<int>  dfs(vector<vector<int>>&edges,int startNode){
    int n=edges.size()+1;//n edges means n+1 nodes
    vector<vector<int>>adj(n); //nodes are from 0 to n-1
    for(auto edge:edges){
        int u=edge[0],v=edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>ans;
    dfs(-1,startNode,ans,adj);
    return ans;
}


int main(){
    vector<vector<int>>edges={{0, 1}, {0, 2}, {1, 3}, {1, 4}}; //0 based indexing
    vector<int>ans=dfs(edges,0);
}