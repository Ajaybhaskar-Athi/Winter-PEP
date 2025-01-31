#include<bits/stdc++.h>
using namespace std;

int dfs(int parent, int startNode, vector<vector<int>>& adj, vector<int>& subtreeSize) {
    int totalNodes = 1;
    if(parent!=-1){
        subtreeSize[startNode]=subtreeSize[parent]+1;
    }
    for (auto nbr : adj[startNode]) {
        if (nbr == parent) continue;
        totalNodes += dfs(startNode, nbr, adj, subtreeSize);
    }
    subtreeSize[startNode] = totalNodes;
    return totalNodes;
}

vector<int> countSubtreeNodes(vector<vector<int>>& edges, int startNode, vector<int>& queries) {
    int n = edges.size() + 1;
    vector<vector<int>> adj(n);
    for (auto edge : edges) {
        int u = edge[0], v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> subtreeSize(n, 0);
    dfs(-1, startNode, adj, subtreeSize);

    vector<int> ans;
    for (int q : queries) {
        ans.push_back(subtreeSize[q]);
    }

    return ans;
}

int main() {
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {1, 4}};
    vector<int> queries = {0, 1, 2, 3, 4};
    vector<int> ans = countSubtreeNodes(edges, 0, queries);

    for (int val : ans) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
