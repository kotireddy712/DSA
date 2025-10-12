// Question :: 435 - https://leetcode.com/problems/non-overlapping-intervals/ 
 
 int eraseOverlapIntervals(vector<vector<int>>& intervals) 
    {
        int n = intervals.size();
        sort
        (intervals.begin(),intervals.end(),
        [](vector<int>& a,vector<int> b)
        {
            // if(a[1] == b[1])
            // {
            //     return a[0] > b[0];
            // }
            // else
            // {
                return a[1] < b[1];
            //}
        }
        );
        int count = 0;
        int prevend = intervals[0][1];
        for(int i = 1; i < n;i++)
        {
            if(intervals[i][0] < prevend)
            {
                count++;
            }
            else
            {
                prevend = intervals[i][1];
            }
            // vector<int> temp = intervals[i];
            // vector<int> temp1 = intervals[i+1];
            // if(temp[1] > temp1[0])
            // {
            //     count++;
            //     int j = i+2;
            //     if(j >= n)
            //     {
            //         break;
            //     }
            //     temp1 = intervals[j];
            //     while( j < n && temp[1] > temp1[0])
            //     {
            //         j++;
            //         count++;
            //         if(j < n)
            //         {
            //              temp1= intervals[j];
            //         }
            //     }
            //     i = j;
            // }
            // else
            // {
            //     i++;
            // }
        }
        return count;
    }