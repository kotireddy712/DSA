// Question :: 56 - https://leetcode.com/problems/merge-intervals/description/
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        //** SORT BY ""starting time""" ascending order.. if equal ascedning by finshing time..
        sort
        ( intervals.begin(),intervals.end(),
          [](vector<int>& a, vector<int>& b)
          {
                if(a[0] == b[0])
                {
                    return a[1] < b[1];
                }
                return a[0] < b[0];
          }
        );
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++)
        {
            vector<int>& temp = result.back(); //** by refernce.. */
            if( intervals[i][0] > temp[1]  )
            {
                result.push_back(intervals[i]);
            }
            else
            {
                // if(intervals[i][1] > temp[1])
                // {
                    temp[1] = max(intervals[i][1],temp[1]); //**
                //}
            }
        }
        return result; 
    }