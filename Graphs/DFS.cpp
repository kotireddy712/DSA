    ----- ** BASIC DFS - Implementation ** ---------------- 
    vector<int> result; //* Globally declared */
    void BackTrack(int node,vector<vector<int>>& adj,vector<bool>& colour)
    {
        colour[node] = true;
        for(int x : adj[node])
        {
            if(colour[x] == false)
            {
                result.push_back(x);
                BackTrack(x,adj,colour);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) 
    {
       int n = adj.size();
       vector<bool> colour(n,false);
       result.push_back(0);
       BackTrack(0,adj,colour);
       return result;
    }
        ** T.C == O(V+E) , S.C == O(V+E) .. **