int SubsetTarget(vector<int>& nums,int target1)
{
    int n = nums.size();
    vector<vector<int>> dp(n+1,vector<int>(target1+1,0));
    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = 1; //** base-case in rec.
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= target1; j++)
        {
            int not_take = dp[i-1][j];
            int take = 0;
            if(nums[i-1] <= j)
            {
                take = dp[i-1][j-nums[i-1]]; //*
            }
            dp[i][j]= take+not_take;
        }
    }
    return dp[n][target1];
}
int NoOfWays(vector<int>& nums,int target)
{
    int total_sum = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++)
    {
        total_sum += nums[i];
    }
    int Sum1 = (total_sum + target) / 2;
    if( total_sum + target < 0 || (target+total_sum)%2 != 0 )
    {
        return 0; //** false;
    }
    return SubsetTarget(nums,Sum1);
}