// Question Link :: -->> https://leetcode.com/problems/number-of-enclaves/?utm=codolio
//Question number -- "1020"

class Solution {
public:
//# to optimise code here only space complexoty can be done :: for taht insted of visited:: make - grid of visisted marked as '0"'
    int count  = 0;
    void recursive(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<bool>>& visited,vector<pair<int,int>>& dir)
    {
                for(auto& [dx,dy] : dir)
                {
                    int newx = i + dx;
                    int newy = j + dy;
                    if( newx >= 0 && newx < n && newy >= 0 && newy < m )
                    {
                        if( grid[newx][newy] == 1 && visited[newx][newy] == false ) 
                        {
                            count--;
                            visited[newx][newy] = true;
                            recursive(newx,newy,n,m,grid,visited,dir);
                        }
                    }
                }
    }
    int numEnclaves(vector<vector<int>>& grid) 
    {
        //int n = grid.size();
        int n = grid.size();
        int m = grid[0].size();
        for(int i =0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if( grid[i][j] == 1 ) {
                    count++;
                }
            }
        }
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int i = 0; i < n; i++)
        {
            if( grid[i][0] == 1 && !visited[i][0] )
            {
                count--;
                visited[i][0] = true;
                recursive(i,0,n,m,grid,visited,dir);
            }
        }
        // # 2. Only considering the last column ..[i][n-1];
        for(int i = 0; i < n; i++)
        {
            if( grid[i][m-1] == 1 && !visited[i][m-1] )
            {
                count--;
                visited[i][m-1] = true;
                recursive(i,m-1,n,m,grid,visited,dir);
            }
        }
        //# first row [0]
        for(int j = 0; j < m; j++)
        {
            if( grid[0][j] == 1 && !visited[0][j] )
            {
                count--;
                visited[0][j] = true;
                recursive(0,j,n,m,grid,visited,dir);
            }
        }
        //# last row ..(n-1)
        for(int j = 0; j < m; j++)
        {
            if( grid[n-1][j] == 1 && !visited[n-1][j] )
            {
                count--;
                visited[n-1][j] = true;
                recursive(n-1,j,n,m,grid,visited,dir);
            }
        }
        return count;
    }
};