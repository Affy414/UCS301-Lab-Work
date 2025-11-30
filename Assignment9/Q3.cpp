#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
    int u,v,w;
};

bool cmp(Edge a, Edge b){
    return a.w < b.w;
}

int findSet(int u, vector<int> &parent){
    if(parent[u] != u) parent[u] = findSet(parent[u], parent);
    return parent[u];
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<Edge> edges(m);
    for(int i=0;i<m;i++){
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    // KRUSKAL
    sort(edges.begin(), edges.end(), cmp);
    vector<int> parent(n);
    for(int i=0;i<n;i++) parent[i] = i;
    int kruskalCost = 0;
    for(auto e : edges){
        int u = findSet(e.u, parent);
        int v = findSet(e.v, parent);
        if(u != v){
            kruskalCost += e.w;
            parent[u] = v;
        }
    }

    // PRIM
    vector<vector<pair<int,int>>> adj(n);
    for(auto e : edges){
        adj[e.u].push_back({e.v,e.w});
        adj[e.v].push_back({e.u,e.w});
    }
    vector<bool> vis(n,false);
    int primCost = 0;
    vector<int> key(n,1e9);
    key[0]=0;
    for(int count=0;count<n;count++){
        int u=-1;
        for(int i=0;i<n;i++){
            if(!vis[i] && (u==-1 || key[i]<key[u])) u=i;
        }
        vis[u]=true;
        primCost += key[u];
        for(auto p: adj[u]){
            int v = p.first;
            int w = p.second;
            if(!vis[v] && w<key[v]) key[v]=w;
        }
    }

    cout << "Kruskal MST cost: " << kruskalCost << endl;
    cout << "Prim MST cost: " << primCost << endl;
    return 0;
}
