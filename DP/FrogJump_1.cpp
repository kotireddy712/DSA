// QUESTION :: GFG :: https://www.geeksforgeeks.org/problems/geek-jump/1?utm_source=chatgpt.com

    int Minimum(vector<int>& dp,vector<int>& height,int idx)
    {
        if( idx  == 0 )
        {
            return 0;
        }
        if(dp[idx] != -1) //** Over-Lapping Sub problems..
        {
            return dp[idx];
        }
        int F_step = Minimum(dp,height,idx-1) + abs( height[idx]-height[idx-1] );
        int S_step = INT_MAX;
        if(idx >= 2)
        {
            S_step = Minimum(dp,height,idx-2) + abs(height[idx-2]-height[idx]);
        }
        return dp[idx] = min(F_step,S_step);
    }
    int minCost(vector<int>& height) 
    {
        int n = height.size();
    //     vector<int> dp(n+1,-1); //** size of "n"-enough ..
    //   //  int mini =  Minimum(dp,height,n-1); ***
    //   // return mini;
   //**  ------------------------ **//
    //   dp[0] = 0;
    //   dp[1] = abs(height[1] - height[0]);
    //   for(int i = 2; i < n; i++)
    //     {
    //         dp[i] = min(dp[i-1]+abs(height[i-1]-height[i]),dp[i-2]+abs(height[i-2]-height[i]));
    //     }
    // return dp[n-1];
   //** ----------------------------- **//
    int prev2 = 0;
    int prev = abs(height[1]-height[0]);
    int curri;
    for(int i = 2; i < n; i++)
    {
        curri = min(prev+abs(height[i-1]-height[i]),prev2+abs(height[i-2]-height[i]));
        prev2 = prev;
        prev = curri;
    }
    return prev;
    }