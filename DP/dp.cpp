
// * You are allowed to reduce any element by 1, 2, or 5.

// Your goal is to make all numbers equal — so you’re really asking:

// How many steps of (−1, −2, or −5) are needed to make all arr[i] equal?

// * When making numbers equal, we can choose any target value T that everyone will end up with.

// Usually, the best choice is around the minimum value in the array.

// Why?
// Because we can only decrease, not increase, values —
// so we can’t go higher than the smallest element.
// But sometimes going slightly below the smallest value (min−1, min−2, …) can give fewer total operations because of the 1/2/5 grouping.


int equal(vector<int> arr) 
{
    int n = arr.size();
    auto it = min_element(arr.begin(),arr.end());
    int final = INT_MAX;
    for(int j = 0; j <= 4; j++)
    {
        int count = 0;
        int target = (*it) - j;
        for(int i = 0; i < n; i++)
        {
            int diff = arr[i] - target;
            if(diff == 0)
            {
                continue;
            }
            int a = diff/5;
            int r1 = diff%5;
            int b = r1/2;
            int r2 = r1%2;
            int c = r2;
            count = count + a + b + c;  
            //arr[i] = arr[i] - diff;
        }
        final = min(final,count);
    }
    return final;
}
------------------------------------------------------
int tutzkiAndLcs(string a, string b) 
{
    int s1 = a.size();
    int s2 = b.size();
    vector<vector<int>> dp_P(s1+1,vector<int>(s2+1,0)); //** indexing to avoid "-1"
    // for(int i = 0; i <= s1; i++)
    // {
    //     dp_P[i][0] = 0;
    // }
    // for(int i = 0; i <= s2; i++)
    // {
    //     dp_P[0][i] = 0;
    // }
    for(int i = 1; i <= s1; i++)
    {
        for(int j = 1; j <= s2; j++)
        {
            if(a[i-1] == b[j-1])
            {
                dp_P[i][j] = 1 + dp_P[i-1][j-1];
            }
            else
            {
                dp_P[i][j] = max(dp_P[i][j-1],dp_P[i-1][j]);
            }
        }
    }
    vector<vector<int>> dp_S(s1+2,vector<int>(s2+2,0));
    for(int i = s1-1; i >= 0 ; i--)
    {
        for(int j = s2-1; j >= 0; j--)
        {
            if(a[i] == b[j])
            {
                dp_S[i][j] = 1 + dp_S[i+1][j+1];
            }
            else
            {
                dp_S[i][j] = max(dp_S[i+1][j],dp_S[i][j+1]);
            }
        }
    }
    int initial_leng = dp_P[s1][s2];
    int ans  = 0;
    for (int i = 0; i <= s1; i++) 
    {
        vector<bool> used(256, false);
        for (int j = 0; j < s2; j++) 
        {
            char c = b[j];
            if (!used[c] && dp_P[i][j] + dp_S[i][j+1] == initial_leng) 
            {
                used[c] = true;
                ans++;
            }
        }
    }
    return ans;
    // int initial = LCSlength(a,b);
    // int ans = 0;
    // unordered_set<char> common;
    // for (char c : b)
    // {
    // if (b.find(c) != string::npos)
    // {
    //     common.insert(c);
    // }
    // }
    // //set<pair<int,char>> used;
    // for (char x : common) 
    // {
    //     for (int pos = 0; pos <= (int)a.size(); pos++) 
    //     {
    //         string temp = a.substr(0, pos) + x + a.substr(pos);
    //         if ( LCSlength(temp, b) == initial + 1 ) 
    //         {
    //             ans++;
    //           //  used.insert({pos, x});
    //         }
    //     }
    // }
    // return ans;
}
---------------------------------------------
long Minimum(vector<vector<long>>& dp, vector<long>& nums,int i,int target)
{
    if( target == 0 )
    {
        return 1;
    }
    if( i < 0 )
    {
        return 0;
    }
    if( dp[i][target] != -1)
    {
        return dp[i][target];
    }
    long not_taken = Minimum(dp,nums,i-1,target);
    long taken = 0;
    if(target >= nums[i])
    {
        taken = Minimum(dp,nums,i,target-nums[i]);
    }
    return dp[i][target]=not_taken+taken;
}
long getWays(int n, vector<long> c) 
{
    int target = n;
    int k = c.size();
    vector<vector<long>> dp(k,vector<long>(target+1,-1));
   return Minimum(dp,c,k-1,target);
}
--------------------------------------------------
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
            // else
            // {
            //     dp[i][j] = dp[i-1][j];
            // }
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
-----------------------------------------------
int LCS(string& s,string& t)
{
    int m = s.size();
    int n = t.size();
    vector<vector<int>> dp(m+1,vector<int>(n+1,0));
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(s[i-1] == t[j-1])
            {
                  dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[m][n];
}
int LPS(string& s) //** palindrome longest sub-seq..
{
    string temp = s;
    reverse(temp.begin(),temp.end());
    return LCS(s,temp);
}
int longestPalindromicSubsequence(string s, int k) 
{
    string t = s;
    reverse(t.begin(), t.end());
    int n = s.size();
    vector<vector<int>> dp_P(n + 1, vector<int>(n + 1, 0));
    vector<vector<int>> dp_S(n + 2, vector<int>(n + 2, 0));
    for(int i = 1; i <= n; i++) 
    {
        for(int j = 1; j <= n; j++) 
        {
            if( s[i - 1] == t[j - 1] )
            {
                dp_P[i][j] = 1 + dp_P[i - 1][j - 1];
            }
            else
            {
                dp_P[i][j] = max(dp_P[i - 1][j], dp_P[i][j - 1]);
            }
        }
    }
    for( int i = n - 1; i >= 0; i-- ) 
    {
        for (int j = n - 1; j >= 0; j--) 
        {
            if (s[i] == t[j])
            {
                dp_S[i][j] = 1 + dp_S[i + 1][j + 1];
            }
            else
            {
                dp_S[i][j] = max(dp_S[i + 1][j], dp_S[i][j + 1]);
            }
        }
    }
    int initial = LPS(s);
    if( k == 0 )
    {
        return 26 * (n + 1);
    }
    int ans = 0;
    for(int pos = 0; pos <= n; pos++) 
    {
        vector<bool> used(26, false);
        for(char c = 'a'; c <= 'z'; c++) 
        {
            string ns = s.substr(0, pos) + c + s.substr(pos);
            int newLPS = LPS(ns);
            if( newLPS - initial >= k ) 
            {
                if( !used[c - 'a'] ) 
                {
                    used[c - 'a'] = true;
                    ans++;
                }
            }
        }
    }
    return ans;
}
------------------------------------------------------