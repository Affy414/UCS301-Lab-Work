#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int start;
    cin >> start;
    vector<int> dist(n,1e9);
    dist[start]=0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,start});
    while(!pq.empty()){
        pair<int,int> top = pq.top(); pq.pop();
        int d = top.first;
        int u = top.second;
        if(d > dist[u]) continue;
        for(auto p : adj[u]){
            int v = p.first;
            int w = p.second;
            if(dist[u]+w < dist[v]){
                dist[v] = dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    for(int i=0;i<n;i++)
        cout << dist[i] << " ";
    return 0;
}
