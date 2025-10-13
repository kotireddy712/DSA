    // GFG Link :: https://www.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1?utm_source=chatgpt.com

    //** But in original question we cant apply greedy- ONLY DP why ?? */
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) 
    {
        int n = wt.size();
        vector<pair<float,int>> fraction;
        for(int i = 0; i < n; i++)
        {
            float ratio = (float) (val[i]) / wt[i];
            fraction.push_back({ratio,i});
        }
        sort //** sort in descending order by raios in it (val[i]/wt[i]).. per kg cost..
        (fraction.begin(),fraction.end(),
        [](pair<float,int> &a,pair<float,int> &b)
        {
            return a.first > b.first;
        }
        );
        double max_value = 0;
        for(int i = 0; i < n; i++)
        {
            pair<float,int> p = fraction[i];
            int indx = p.second;
            if( capacity >= wt[indx] )
            { 
                capacity = capacity - wt[indx];
                max_value = max_value + val[indx];
            }
            else if ( capacity > 0 )
            {
                int nr = capacity * val[indx];
                capacity = 0;
                double fract = (double) (nr) / wt[indx];
                max_value = max_value + fract;
            }
            else if (capacity  == 0)
            {
                return max_value;
            }
        }
        return max_value;
    }