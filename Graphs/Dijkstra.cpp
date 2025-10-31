#include <bits/stdc++.h>
using namespace std;
void DijkstraAlgo(vector<pair<int,int>> Adj[],int n)
{
    vector<int> distance(n,INT_MAX); //** final shortest-distance ((final-value ..)) */
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; //** min-HEAP ** */ first = distance; second = node..
    pq.push({0,0});
    distance[0] = 0;
    while( !pq.empty() )
    {
        auto [d,v] = pq.top();
        pq.pop();
        if( d > distance[v] )
        {
            continue; //** Out-Dated value - continue .. */
        }
        for( auto [node,wt] : Adj[v] )
        {
            if(distance[node] > distance[v] + wt)
            {
                distance[node] = distance[v]+wt;
                pq.push({distance[node],node});
            }
        }
    }
    cout << "All Distances from source vertex 0 is :: " << "\n";
    for(int i = 0; i < n; i++)
    {
        cout << distance[i] <<" ";
    }

}
int main()
{
    int n;
    cin >> n; //* No.of.Nodes ..
    vector<vector<pair<int,int>>> adj(n); // OR -- vector<pair<int,int>> ""adj[n]""
    int edges;
    cin >> edges;
    //** Assume it as un-directed graph (no-repated edges not given in input; we asuume and take since:: un-directed ..) */
    for(int i = 0; i < edges; i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    DijkstraAlgo(adj,n);
}

--------------------"" T.C :: O(E.log{V}) "" && { S.C :: O(V + E) for adjacency list ,O(V) for distance array } ---------------------------