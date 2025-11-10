//** It gives total no.of.ways to make sum of coins(infinetly taken coins..) to target */

long No_Of_Ways(vector<vector<long>>& dp,vector<long>& coins,int indx,int target)
{
    if( target == 0 )
    {
        return 1;
    }
    if(idx < 0)
    {
        return 0;
    }
    if(dp[indx][target] != -1)
    {
        return dp[indx][target];
    }
    long not_taken = No_Of_Ways(dp,coins,indx-1,target);
    long taken = 0;
    if(target >= coins[idx])
    {
        taken = No_Of_Ways(dp,coins,indx,target-coins[indx]);
    }
    return dp[indx][target] = taken + not_taken;
}

long GetWays(vector<long>& coins,int target)
{
    int n = coins.size();
    vector<vector<long>> dp(n,vector<int>(target+1,-1));
    return No_Of_Ways(dp,coins,n-1,target);
}