// Question -->> :: https://leetcode.com/problems/rotting-oranges/?utm=codolio
//question number -- 994
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        //0-empty,1-fresh,2-rotten
        //each time stamp all rotten its adjacent will become rotten ..
        int total_fresh_fruits = 0;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0;j < n; j++)
            {
                if(grid[i][j] == 1)
                {
                    total_fresh_fruits++;
                }
            }
        }
        queue<pair<int,int>> q;
        for(int i = 0; i < m;i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
            }
        }
        int time = 0;
        while( !q.empty() )
        {
            int level = q.size();
            int flag = -1;
            for(int i = 0; i < level;i++)
            {
                auto [x,y] = q.front();
                q.pop();
                for(auto [dx,dy]: dir)
                {
                    if( x+dx >= 0 && x+dx < m && y+dy >= 0  && y+dy < n)
                    {
                        if(grid[x+dx][y+dy] == 1)
                        {
                            q.push({x+dx,y+dy});
                            grid[x+dx][y+dy] = 2;
                            total_fresh_fruits--;
                            flag=1;
                        }
                    } 
                }
            }
            if(flag == 1)
            {
                time++;
            }
        }
        if(total_fresh_fruits != 0)
        {
            return -1;
        }
        return time;
    }
};