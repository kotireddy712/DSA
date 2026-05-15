// Question link ::: https://leetcode.com/problems/01-matrix/?utm=codolio
// Queation NUmber :: 542
class Solution 
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int m = mat.size();
        int n = mat[0].size();
        //vector<vector<bool>> visited(m,vector<bool>(n,false)); # his also actually no need to track unvisited elements,just :: given "mat" is enough /..
        queue<pair<int,int>> q; //** x-cor,y-cor, {value -- -- ---}
        for(int i = 0; i<m; i++)
        {
            for(int j = 0; j<n; j++)
            {
                if( mat[i][j] == 0 )
                {
                   // distance[i][j] = 0;
                    //visited[i][j] = true;
                    q.push({i,j});
                }
                else
                {
                    mat[i][j] = -1;
                }
            }
        }
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        //** solve like :: ""multi - source bfs""" :: from all 0's ::
        //# think of reverse of question since,they asked to find distances of "1" u do from "0"
       // # Your thinking is natural initially:
        // ## 1 . For every 1, find nearest 0
        // # # 2 . But algorithmically, it is inefficient. The key shift is:
        // How can we solve ALL cells together efficiently?
        // reverse perspective:
            // **  all 0s spread outward simultaneously  **
        while( !q.empty() )
        {
            auto [x,y] = q.front(); //** dont do refrence here 
            q.pop();
            for(auto & [dx,dy] : dir)
            {
                if( x+dx >= 0 && x+dx < m && y+dy >= 0 && y+dy < n )
                {
                    if( mat[x+dx][y+dy] == -1 )
                    {
                       // visited[x+dx][y+dy] = true;
                        q.push({x+dx,y+dy});
                        mat[x+dx][y+dy] = mat[x][y]+ 1;
                    }
                }
            }
        }
        return mat;
    }
};