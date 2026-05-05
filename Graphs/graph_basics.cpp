#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int Adj[n][n]; // vector<vector<int>> Adj(n); == also can be used ..
    for(int i = 0; i < n; i++)
    {
        int e1,e2;
        cin >> e1 >> e2;
        Adj[e1][e2] = 1;
    }
    return 0;
}