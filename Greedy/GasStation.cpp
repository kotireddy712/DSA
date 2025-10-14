// Question :: 134 - https://leetcode.com/problems/gas-station/description/
// ** Keep Tracking of Two pointers/varabiles and anyway if we start from anypoint;total fuel from index is same..
// **  just need to find start_index..

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int n = gas.size();
        int curr_gas = 0;
        int total_gas = 0;
        int start = 0;
        for(int i = 0; i < n; i++)
        {
            int diff = gas[i]-cost[i];
            total_gas = total_gas + diff;
            curr_gas = curr_gas + diff;
            if(curr_gas < 0)
            {
                curr_gas = 0;
                start = (i+1)%n;
            }
        }
        return (total_gas >= 0)? start : -1;
    }
