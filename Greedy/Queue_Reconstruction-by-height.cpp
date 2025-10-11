Question - 406 :: https://leetcode.com/problems/queue-reconstruction-by-height/description/
1. Sort by descending order by their heights (hi), if same then sort ascending order by people infront.(ki)    
2. Heights of taller keep first, since:: shorter ones will not afffect larger so, we can keep

    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        int n = people.size();
        sort
        (
            people.begin(),people.end(),
            [](vector<int>& a,vector<int>& b) //* custom - comparator (Lambda Function)..
            {
                if(a[0] == b[0])
                {
                    return a[1] < b[1];
                }
                return a[0] > b[0];
            }
        
        );
        vector<vector<int>> result;
        for(int i = 0; i < n; i++)
        {
            vector<int> temp = people[i];
            int j = people[i][1];
            result.insert(result.begin()+j,temp);
        }
        return result;
    }