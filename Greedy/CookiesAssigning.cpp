Question Link :: 455 . https://leetcode.com/problems/assign-cookies/description/

int findContentChildren(vector<int>& g, vector<int>& s) 
{
    //** Here Greedy ::
    // So, the best local choice is:
    // 👉 Give the smallest available cookie that can satisfy the least greedy child.
    int count  = 0;
    int n = g.size(); //* N - CHILDEREN''S..
    int m = s.size(); //** M - COKKIES ..
    sort(g.begin(),g.end());
    sort(s.begin(),s.end());
    int j = 0;
    int i = 0;
    while( i < n && j < m )
    {
        if( s[j] >= g[i] )
        {
            count++;
            i++;
        }
        j++;
    }
    return count;
}