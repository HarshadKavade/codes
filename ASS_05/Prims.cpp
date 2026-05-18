#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

void Prims(int v, vector<vector<pii>>& adj) {

    priority_queue<pii,
                   vector<pii>,
                   greater<pii>> pq;

    vector<bool> vis(v, false);

    pq.push({0,0});
    int total_wt=0;

    cout << "Edges in Minimum Spanning Tree:\n";

    while(!pq.empty()) {

        int wt = pq.top().first;
        int node = pq.top().second;

        pq.pop();

        if(vis[node])
            continue;

        vis[node] = true;
        total_wt+=wt;

        cout << "Vertex " << node
             << " added in MST with Edge Weight : "
             << wt << endl;

        for(int i = 0; i < adj[node].size(); i++) {

            int ver = adj[node][i].first;
            int wtt = adj[node][i].second;

            if(!vis[ver]) {
                pq.push({wtt, ver});
            }
        }
    }
    cout<<"Minimum Weight: "<<total_wt<<endl;
}

int main() {

    int v, e;

    cout << "Enter no of vertices : ";
    cin >> v;

    cout << "Enter no of edges : ";
    cin >> e;

    vector<vector<pii>> adj(v);

    for(int i = 0; i < e; i++) {

        int u, v2, w;
        cin >> u >> v2 >> w;

        adj[u].push_back({v2,w});
        adj[v2].push_back({u,w});
    }

    Prims(v, adj);

    return 0;
}