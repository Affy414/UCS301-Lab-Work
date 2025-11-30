#include <iostream>
#include <vector>
using namespace std;

void dfs(int u, vector<vector<int>> &adj, vector<bool> &visited){
    visited[u] = true;
    cout << u << " ";
    for(int v : adj[u]){
        if(!visited[v])
            dfs(v, adj, visited);
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for(int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int start;
    cin >> start;
    vector<bool> visited(n,false);
    dfs(start, adj, visited);
    return 0;
}
