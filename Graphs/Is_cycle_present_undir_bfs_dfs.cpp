#include <bits/stdc++.h>
using namespace std;

bool IsCyclePressent(vector<vector<int>>& adj_list)
{
    int n = adj_list.size(); //** no.of.verticies .. */
    vector<bool> visited(n,false); //** "-1" : un-visited and "0" : parent :: "1" ;; child  == doing like "bi-partite graph" */
    //** vector-pair -->> ::  */
    queue<pair<int,int>> q;
    q.push({0,-1});//* child,parent
    visited[0] = true;
    while(!q.empty())
    {
        auto& [child,parent] = q.front();
        q.pop();
        for(int neigh : adj_list[child])
        {
            if(!visited[neigh])
            {
                visited[neigh] = true;
                q.push({neigh,child});
            } 
            else if(neigh != parent)
            {
                return true;//* cycle exsists ..
            }
        }
    }
    return false; // ** no cycle exsists ..
}

bool IsCyclePresent(vector<vector<int>>& adj_list,int node,int parent,vector<bool>& visited)
{
    visited[node] = true;
    for(int neigh : adj_list[node])
    {
        if(!visited[neigh])
        {
            if( IsCyclePresent(adj_list,neigh,node,visited) )
            {
                return true; //** cycle exsists ... ... . ..  */
            }
        }
        else if(neigh != parent)
        {
            return true; //* cycle- exsists
        }
    }
    return false;
}