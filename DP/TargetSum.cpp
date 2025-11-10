Question ::  494 - https://leetcode.com/problems/target-sum/description/

1. 
dp[i][s] = NUMBER OF WAYS to pick elements from nums[0...i] such that their sum equals s.
--------------
Specifically:
---------
i → how many elements we considered
s → which sum we are trying to make
-----------------------------   
    int findTargetSumWays(vector<int>& nums, int target) //** target is diiference bettwen '+' and '-' .. */
    {
        int n = nums.size();
        int sum = 0;
        for(auto i : nums)
        {
            sum = sum + i;
        }
        if ( (target + sum) % 2 != 0 || target > sum || target < -sum )
        {
            return 0;
        }
        int new_Target = (target + sum)/2;
        vector<vector<int>> dp(n,vector<int>(new_Target+1,0));
        for(int i = 0; i < n; i++)
        {
            dp[i][0] = 1;
        }
        if ( nums[0] == 0 ) //**  mainly in constainyts base case - "take +0 and not-take "-0" 2-subsets..*/
        {
            dp[0][0] = 2; // +0 or -0
        }
        else
        {
            dp[0][0] = 1; //**
            if(nums[0] <= new_Target)
            {
                dp[0][nums[0]] = 1;
            }
        }
        for(int i = 1; i < n; i++)
        {
            for(int s = 0; s <= new_Target; s++) //** s == 0 .. it should update when 2-'0's have :: generally s starts from ""1""".. 
            {
                int not_take = dp[i-1][s];
                int take = 0;
                if(nums[i] <= s)
                {
                    take = dp[i-1][s-nums[i]];//** wont chnage if :: nums[i] == 0 .. */
                }
                dp[i][s] = take + not_take;
            }
        }
        return dp[n-1][new_Target];
    }