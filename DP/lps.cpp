#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int l = s.size();
    vector<vector<int>> dp(l+1,vector<int>(l+1,0));
    for(int i=l-1;i>=0;i--)
    {
        dp[i][i]=1;
        for(int j=i+1;j<l;j++)
        {
            int temp= max(dp[i+1][j],dp[i][j-1]);
            if(s[i]==s[j])
            {
                temp = max(2+dp[i+1][j-1],temp);
            }
            dp[i][j]=temp;
        }
    }
    cout << dp[0][4];
}