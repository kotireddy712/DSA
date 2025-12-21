#include<bits/stdc++.h>
using namespace std;
int SmallestSubArraySize(vector<int>& nums,int target)
{
    int l = 0;
    int r = 0;
    int n = nums.size();
    int mini = INT_MAX;
    int prefix_sum = 0;
    while(r < n)
    {
        prefix_sum += nums[r];
        while(prefix_sum > target) //** if we keep equals it will destory EXACT SUBARRAY .. */
        {
            prefix_sum -= nums[l];
            l++;
        }
        if(prefix_sum == target)
        {
            mini = min(mini,r-l+1);
        }
        r++;
    }
    return mini;
}
int main()
{
    vector<int> nums;
    int k;
    cin >> k;
    for(int i = 0; i < k; i++)
    {
        int t;
        cin >> t;
        nums.push_back(t);
    }
    int need;
    cin >> need;
unordered_map<int,int> mp;
mp[0] = -1; //** Sum, Index till where ..  ..  */
//** nums  */
int n = nums.size();
long long prefix_sum  = 0;
int mini = INT_MAX;
for(int i = 0; i < n; i++)
{
    prefix_sum = prefix_sum + nums[i];
    int target = (prefix_sum - need);
    if(mp.find(target) != mp.end())
    {
        mini = min(mini,i-mp[target]);
    }
    mp[prefix_sum] = i;
}
cout << mini <<"\n";
return 0;
}