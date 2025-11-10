int LCS(string& s1, string& s2)
{
    int n = s1.size();
    int m = s2.size();
    //** shifiting of indices to avoid "-1" case.. */
    vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
    for(int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }
    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    
    string MATCH = "";
    int len = dp[m][n]; //** IMP.. max.sub-seq. length */
    int idx = len-1;
    for(int i = 0; i < len; i++)
    {
        MATCH+='$';
    }
    int i = n;
    int j = m;
        while( i > 0 && j > 0 )
        {
            if(s1[i-1] == s2[j-1])
            {
                MATCH[idx] = s1[i-1];
                idx--;
                i = i-1;
                j = j -1;
            }
            else if (dp[i-1][j] > dp[i][j-1])
            {
                i = i-1;
            }
            else
            {
                j = j-1;
            }
        }
            return MATCH; //** matched string( sub-sequence) out .. */
    return dp[n][m];
}