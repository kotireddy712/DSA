// Question :: - 452 - https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/

// ** Sort by Finshing X-co-ordinate (Not by first Value ) :: ex:: [1,10], [2,6], [7,12] (* sort by first value not works fucking all time..)

    int findMinArrowShots(vector<vector<int>>& points) 
    {
        int n = points.size();
        sort
        ( points.begin(),points.end(),
          [](vector<int>& a,vector<int>& b)
          {
            return a[1] < b[1]; //** ascending order by **second** value;
          }
        );
        int prev = points[0][1];
       // int sticks = 1;
       int count = 0;
        for(int i = 1; i < n; i++)
        {
            // if(points[i][0] > prev)
            // {
            //     sticks++;
            //     prev = points[i][1];
            // }
        if(points[i][0] <= prev)
        {
            count++;
        }
        else
        {
            prev = points[i][1];
        }
        }
        return (n-count);
       // return sticks;
    }