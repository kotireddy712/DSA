//Question link :: -- https://leetcode.com/problems/number-of-provinces/?utm=codolio
//Question Number :: 547
class Solution 
{
public:
    void dfs(int node,vector<vector<int>>& adj,vector<int>& visited) {
        visited[node] = 1;
        for(auto neighbour : adj[node])
        {
            if(!visited[neighbour]) {
                dfs(neighbour,adj,visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int n = isConnected.size(); //* no.of.vertices (0r) cities ..
        vector<int> visited(n,0); //* 0 --> not-visited; 1--> visited ...
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if( i != j && isConnected[i][j] == 1 )
                {
                    adj[i].push_back(j);
                }
            }
        }
        int count  = 0;
        for(int i = 0; i < n; i++) {
            int start_node = i;
            if( !visited[start_node] ) {
                dfs(start_node,adj,visited);
                count++;
            }
        }
        return count;
    }
};