// Question :: 621 - https://leetcode.com/problems/task-scheduler/description/
    int leastInterval(vector<char>& tasks, int n) 
    {
        int m = tasks.size();
        unordered_map<char,int> freq;
        for(int i = 0; i < m; i++)
        {
            freq[tasks[i]]++;
        }
        priority_queue<int> pq; //** max - heap by default..
        int maxi = 0; //** case-2 :: ex :: (3,A),(2,B),(2,C):: n= 1 -- Round Bobin Helpfull..)) used for no idle needed already puuk packed schuedules ...
        for(auto i : freq)
        {
            maxi = maxi + i.second;
            pq.push(i.second);
        }
        int count  = 0;
        int prev = pq.top();
        pq.pop();
        count = prev + ( (prev-1) * n );
        while(!pq.empty() && pq.top() == prev)
        {
           count++;
           pq.pop();
        }
        int final = max(maxi,count);
        return final;
    }