#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

void Dijkstra(int src, vector<vector<pii>>& adj, int v){

    priority_queue<
                    pii,
                    vector<pii>,
                    greater<pii>
                  > pq;

    vector<int> dist(v, INT_MAX);

    dist[src] = 0;

    pq.push({0, src});

    while(!pq.empty()){

        int currnode = pq.top().second;
        int currdist = pq.top().first;

        pq.pop();

        // Skip old larger distances
        if(currdist > dist[currnode])
            continue;

        for(int i = 0; i < adj[currnode].size(); i++){

            int node = adj[currnode][i].first;
            int dis  = adj[currnode][i].second;

            if(dist[currnode] + dis < dist[node]){

                dist[node] = dist[currnode] + dis;

                pq.push({dist[node], node});
            }
        }
    }

    cout << "\nShortest path from Source Node " << src << ":\n";

    for(int i = 0; i < dist.size(); i++){

        if(dist[i] == INT_MAX){

            cout << "Node " << i << " cannot be reached\n";
        }
        else{

            cout << "From " << src
                 << " to " << i
                 << " shortest distance is "
                 << dist[i] << endl;
        }
    }
}

int main(){

    int v, e;

    cout << "Enter no of vertices: ";
    cin >> v;

    cout << "Enter no of edges: ";
    cin >> e;

    vector<vector<pii>> adj(v);

    for(int i = 0; i < e; i++){

        int u, vv, w;

        cin >> u >> vv >> w;

        adj[u].push_back({vv, w});
        adj[vv].push_back({u, w});
    }

    int src;

    cout << "Enter source value: ";
    cin >> src;

    Dijkstra(src, adj, v);
}