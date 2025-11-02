#include <bits/stdc++.h>
using namespace std;
//** can be now from can jump to k-steps (not onlt either 1 or 2 ?? ) */
int Frog_Jump_2(vector<int>& costs,int k)
{
    int n = costs.size();
    vector<int> dp(n,-1); //** better if INT_MAX.. */
    dp[0] = 0;
    for(int i = 1; i < n; i++)
    {
        int temp = INT_MAX;
        for(int j = 1; j <= k; j++)
        {
            if(i-j >= 0)
            {
                int step_cost = dp[i-j] + abs(costs[i]-costs[i-j]);
                temp = min(temp,step_cost);
            }
        }
        dp[i] = temp;
    }
    return dp[n-1];
}