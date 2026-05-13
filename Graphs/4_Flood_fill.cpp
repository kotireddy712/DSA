//Question link ::: -->> https://leetcode.com/problems/flood-fill/description/?utm=codolio
// question number :: 733
class Solution {
public:
    void dfs(int x,int y,int color,vector<vector<int>>& image,vector<pair<int,int>>& dir)
    {
        int old_colour = image[x][y];
        image[x][y] = color;
        for(auto& [dx,dy] : dir)
        {
            if( x+dx >= 0 && x+dx < image.size() && y+dy >= 0 && y+dy < image[0].size() )
            {
                if( image[x+dx][y+dy] == old_colour )
                {
                    dfs(x+dx,y+dy,color,image,dir);
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int m = image.size();
        int n = image[0].size();
        if(image[sr][sc] == color)
        {
            return image;
        }
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        dfs(sr,sc,color,image,dir);
        return image;
    }
};