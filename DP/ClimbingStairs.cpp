// Question - 70 :: https://leetcode.com/problems/climbing-stairs/?utm_source=chatgpt.com

int total(int n,vector<int>& dp)
{
    if( n <= 1 )
    {
        return 1; //** NOT {n} "" This base case keeps the recurrence consistent""".
    }
    if(dp[n] != -1)
    {
        return dp[n];
    }
    return dp[n] = total(n-1,dp)+total(n-2,dp);
}
    int climbStairs(int n) 
    {
       // ** similar to EDGE FINNACOOI-NUMBER PROBLEM ..
        vector<int> dp(n+1,-1);
        int p = total(n,dp);
        // ** we can do space optimisation also..
        // int prev2 = 1;
        // int prev = 1;
        // int curri;
        // for(int i = 2; i <= n; i++)
        // {
        //     curri = prev2 + prev;
        //     prev2 = prev;
        //     prev = curri;
        // }

        return ;
    }