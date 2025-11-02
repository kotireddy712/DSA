// Question - 198  :: https://leetcode.com/problems/house-robber/description/

    int MaxMoney(vector<int>& nums,vector<int>& dp, int idx)
    {
        if(idx < 0)
        {
            return 0;
        }
        if(idx == 0)
        {
            return nums[idx];
        }
        if(dp[idx] != -1)
        {
            return dp[idx];
        }
        int include = nums[idx] + MaxMoney(nums,dp,idx-2);
        int exclude = MaxMoney(nums,dp,idx-1);
        return dp[idx] = max(include,exclude);
    }
    int rob(vector<int>& nums) 
    {
       int n = nums.size();
       vector<int> dp(n,-1);
      // int maxi =  MaxMoney(nums,dp,n-1);
       if (n == 0) return 0;
    if (n == 1) return nums[0];
      dp[0] = nums[0];
      dp[1] = max(nums[0],nums[1]);
      for(int i = 2; i < n; i++)
      {
        int include = nums[i] + dp[i-2];
        int exclude = dp[i-1];
        dp[i] = max(include,exclude);
      }
      return dp[n-1];
      // return maxi;
    }