//** Minimum - Coins Requried ...to make target .. */

int MINIMUM(vector<vector<int>>& dp, vector<int> change,int i,int target)
{
    if(i == 0)
    {
        if(target % change[0] == 0)
        {
            return target/change[0];
        }
        else
        {
            return 1e9; //** --- */
        }
    }
    if(dp[i][target] != -1)
    {
        return dp[i][target];
    }
    int not_taken = 0 + MINIMUM(dp,change,i-1,target);
    int taken = INT_MAX;
    if(target >= change[i])
    {
        taken = 1 + MINIMUM(dp,change,i,target-change[i]);
    }
    return dp[i][target] = min(not_taken,taken);
}
int min_coins(vector<int> change,int target)
{
    int n = change.size();
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    int val = MINIMUM(dp,change,n-1,target);
    if(val >= 1e9)
    {
        return -1;
    }
    return val;
}