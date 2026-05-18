#include <bits/stdc++.h>
using namespace std;

void dfs(int n, vector<vector<int>>& adj, vector<bool>& vis)
{
    vis[n] = true;
    cout << n << " ";

    for(int i = 0; i < adj[n].size(); i++)
    {
        int neighbour = adj[n][i];

        if(!vis[neighbour])
        {
            dfs(neighbour, adj, vis);
        }
    }
}

void BFS(int start, vector<vector<int>>& adj, int n)
{
    vector<bool> vis(n, false);
    vector<int> dist(n, -1);

    queue<int> q;

    vis[start] = true;
    dist[start] = 0;
    q.push(start);

    while(!q.empty())
    {
        int node = q.front();
        q.pop();

        for(int i = 0; i < adj[node].size(); i++)
        {
            int neighbour = adj[node][i];

            if(!vis[neighbour])
            {
                vis[neighbour] = true;
                dist[neighbour] = dist[node] + 1;
                q.push(neighbour);  
            }
        }
    }

    cout << "\nShortest Distance from Computer " << start << ":\n";

    for(int i = 0; i < n; i++)
    {
        cout << "To Computer " << i << " Distance = " << dist[i] << endl;
    }
}

int main()
{
    int n, e;

    cout << "Enter No of computers: ";
    cin >> n;

    cout << "Enter no of connections: ";
    cin >> e;

    vector<vector<int>> adj(n);

    cout << "Enter connections (u v):\n";

    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(n, false);

    cout << "\nConnected computers:\n";

    for(int i = 0; i < n; i++)
    {
        if(!vis[i])
        {
            cout << "Network component: ";
            dfs(i, adj, vis);   
            cout << endl;
        }
    }

    int start;
    cout << "\nEnter starting computer for BFS: ";
    cin >> start;

    BFS(start, adj, n);

    return 0;
}