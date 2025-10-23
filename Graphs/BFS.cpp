    ----- ** BASIC BFS - Implementation ** ---------------- 
    vector<int> bfs(vector<vector<int>> &adj) //** given adjaceny - list (UN-DIRECTED GRAPH)...
    {
        //** if we want to declare a 2-d array with intilisation :: vector<vector<int>> adj(n,vector<int>(n,0));
       vector<int> result;
       int n = adj.size();
       queue<int> q;
       vector<int> colour(n,false);
       q.push(0);
       result.push_back(0);
       colour[0] = true;
       while( !q.empty() )
       {
           int node = q.front();
           q.pop();
           for(auto x : adj[node]) //*
           {
               if(colour[x] == false) //** un-visited */
               {
                   result.push_back(x);
                   q.push(x);
                   colour[x] = true;
               }
           }
       }
       return result;
    }
        ** T.C :: O(V+E);  && S.C :: O(V) **
    ------------------------------------------------------------------


