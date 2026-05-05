class Solution 
{
  public:
    vector<int> dfsOfGraph(int V, vector<vector<int>> edges) {
      

     
    }
    
    vector<int> bfsOfGraph(int V, vector<vector<int>> edges) 
    {
      // edges == {{u,v},...} --> from this we have to create adjacency list ..
      vector<vector<int>> adj(V); // "0"-based indexing ..
      int n = edges.size(); // No.of.Edges

      for(int i = 0; i < n; i++) {
        vector<int> temp = edges[i]; //** just a pair will be there {u,v} */
        adj[temp[0]].push_back(temp[1]);
        adj[temp[1]].push_back(temp[0]);
      }
      // for(auto &e : edges)
      // {
      //   adj[e[0]].push_back(e[1]);
      //   adj[e[1]].push_back(e[0]);
      // } == directly ...

      queue<int> q; //** F.I.F.O */

      vector<bool> visited(V);
      // vector<bool> visited(V,false); == direct formuale...
      
      for(int i = 0; i < V; i++) {
        visited[i] = false;
      }

      q.push(0);
      visited[0] = true;

      vector<int> answer;
      while(!q.empty()) {
        int f_node = q.front();
        q.pop();
        // visited[f_node] = true; failed when :: 1-->2 and 1-->3 and 2-->3 ..
        answer.push_back(f_node);
        for(auto x : adj[f_node]) {
          if(!visited[x])
          {
            q.push(x);
            visited[x] = true;
          }
        }
      }
      return answer; 
    }
};
