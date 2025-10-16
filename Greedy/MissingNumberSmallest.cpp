// Question :: 2598 - https://leetcode.com/problems/smallest-missing-non-negative-integer-after-operations/description/?envType=daily-question&envId=2025-10-16
    // Do add/subract the given values and == Just find remainsers and push and check first smallest number missing which should maximise that..   
     
    int findSmallestInteger(vector<int>& nums, int value) 
    {
        int n = nums.size();
       // sort(nums.begin(),nums.end()); //** sorted or un-sorted NO-ISSUEE..fuckup..
        unordered_map<int,int> M;
        for(int i = 0; i < n; i++)
        {
            int rem = ( (nums[i] % value) + value) % value;
            M[rem]++;
        }
        int x = 0;
        //** finally we worry about remainder's so. use that logic and use them accrdingly.
        while(1)
        {
            int rem = x % value;
            if(M[rem] == 0)
            {
                return x;
            }
            else
            {
                M[rem]--;
                x++;
            }
        }
        return -1;
    }