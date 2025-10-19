// Question ::  945 - https://leetcode.com/problems/minimum-increment-to-make-array-unique/description/

//     1. Sort the array and Check with previous element and amke sure it strictly greater; for that incremeent cost and array values

    int minIncrementForUnique(vector<int>& nums) 
    {
        int n = nums.size();
        sort(nums.begin(),nums.end()); //** ascending-order..
        int moves = 0;
        for(int i = 1; i <n;i++ )
        {
            // while(nums[i] <= nums[i-1])
            // {
            //     moves++;
            //     nums[i]++;
            // }
            int diff = nums[i] - nums[i-1];
            if ( diff <= 0 )
            {
                diff = -diff;
                moves = moves + diff + 1;
                nums[i] = nums[i] + diff+1;
            }
        }
        return moves;
    }