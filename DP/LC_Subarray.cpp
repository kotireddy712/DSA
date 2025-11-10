int LC_Subarray(string& s,string& t)
{
    int m = s.size();
    int n = t.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
    for(int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }
    for(int i = 0; i <= n; i++)
    {
        dp[0][i] = 0;
    }
    int maxi = 0;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(s[i-1] == t[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
                maxi = max(maxi,dp[i][j]);
            }
            else
            {
                dp[i][j] = 0; //** since, there are asking for sub-array's.. */
            }
        }
    }
    return maxi;
}