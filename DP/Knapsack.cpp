    
    QUESTION :: FULL(0/1)- Knapsack :: https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1
    SPACE OPTMISIATION :: we can even do with 1-d "1"-vector no need of curr; just 2nd loop run oppsoiste :: from W -->0.. and keep all prev-enough..

    class Solution 
{
  public:
    int FULL_TAKE(vector<vector<int>> &dp,int idx,int W,vector<int> &val, vector<int> &wt)
    {
        if(idx == 0)
        {
            if(W >= wt[0])
            {
                return val[0];
            }
            return 0;
        }
        if(dp[idx][W] != -1)
        {
            return dp[idx][W];
        }
        int not_take = FULL_TAKE(dp,idx-1,W,val,wt);
        int take = INT_MIN;
        if(W >= wt[idx])
        {
            take  = val[idx] + FULL_TAKE(dp,idx-1,W-wt[idx],val,wt);
        }
        return dp[idx][W]=max(take,not_take);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) 
    {
        int n = wt.size();
      //  vector<vector<int>> dp(n,vector<int>(W+1,0));
        vector<int> prev(W+1,0);
        vector<int> curr(W+1,0);
        for(int w = wt[0]; w <= W; w++)
        {
            prev[w] = val[0];
        }
        // if(W >= wt[0])
        // {
        //     dp[0][wt[0]] = val[0];
        // }
        // for(int w = wt[0]; w <= W; w++)
        // {
        //     dp[0][w] = val[0];
        // }   

        for(int i = 1; i < n; i++)
        {
            for(int w = 0; w <= W; w++)
            {
                int not_take = prev[w]; //dp[i-1][w];
                int take = INT_MIN;
                if( w >= wt[i])
                {
                 take = val[i] + prev[w-wt[i]];//dp[i-1][w-wt[i]];
                }
                curr[w] = max(take,not_take);
               // dp[i][w]=max(take,not_take);
            }
            prev = curr;
        }
        return prev[W];
        //return dp[n-1][W];
        // return (dp[n-1][W] == -1) ? 0 : dp[n-1][W];
        // FULL_TAKE(dp,n-1,W,val,wt);
          //return FULL_TAKE(dp,n-1,W,val,wt);
    }
};