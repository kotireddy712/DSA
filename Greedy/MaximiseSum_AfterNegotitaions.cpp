// Question  - 1005 :: https://leetcode.com/problems/maximize-sum-of-array-after-k-negations/

//  * Main Idea is to sort the array one negatives are flipped ( TWO TIMES SORTING **;)

   int largestSumAfterKNegations(vector<int>& nums, int k) 
    {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int sum = 0;
        if(nums[0] >= 0)
        {
            if(k % 2 == 0)
            {
              sum = sum + nums[0];
            }
            else
            {
                sum = sum - nums[0];
            }
            for(int i = 1; i < n; i++)
            {
                sum = sum + nums[i];
            }
            return sum;
        }
        int j = 0;
        while( j < n && nums[j] < 0 && k > 0 )
        {
            nums[j] = -nums[j];
            k--;
            j++;
        }
        sort(nums.begin(),nums.end()); //*** Removes all un-nescceary conditions.. */
        if(k % 2 == 1) //** If remaining k is even no issue it will split and canel out with same value no issue.. */
        {
           nums[0] = -nums[0];
        }
        for(int i = 0; i < n; i++)
        {
            sum = sum + nums[i];
        }
        return sum;

        // int n = nums.size();
        // sort(nums.begin(),nums.end());
        // int first_value = nums[0];
        // int sum = 0;
        // auto it = lower_bound(nums.begin(),nums.end(),0);
        // int positive_index = it - nums.begin();
        // if (it == nums.end())  
        // {
        //     for (int i = 0; i < n && k > 0; i++)
        //     {
        //         nums[i] = -nums[i];
        //         k--;
        //     }
        //     // ✅ If still k left and odd → flip smallest abs value
        //     sort(nums.begin(), nums.end());
        //     if (k % 2 == 1)
        //         nums[0] = -nums[0];

        //     for (int x : nums) sum += x;
        //     return sum;
        // }
        // if(first_value >= 0)
        // {
        //     for(int i = 1; i < n; i++)
        //     {
        //         sum = sum + nums[i];
        //     }
        //     if( k % 2 == 0 )
        //     {
        //         sum = sum + nums[0];
        //     }
        //     else
        //     {
        //         sum = sum - nums[0];
        //     }
        //     return sum;
        // }
        // else if (first_value < 0)
        // {
        //     if(positive_index >= k)
        //     {
        //         for(int i = 0; i < k; i++)
        //         {
        //             sum = sum - nums[i];
        //         }
        //         for(int i = k; i < n; i++)
        //         {
        //             sum = sum + nums[i];
        //         }
        //         return sum;
        //     }
        //     else if( positive_index < k )
        //     {
        //         if(nums[positive_index] == 0)
        //         {
        //             for(int i = 0; i < n; i++)
        //             {
        //                 if(nums[i] < 0)
        //                 {
        //                     sum = sum - nums[i];
        //                 }
        //                 else
        //                 {
        //                     sum = sum + nums[i];
        //                 }
        //             }
        //             return sum;
        //         }
        //         int remaining_spots = k - positive_index;
        //         if(remaining_spots % 2 == 0)
        //         {
        //             for(int i = 0; i < n; i++)
        //             {
        //                 if(nums[i] < 0)
        //                 {
        //                     sum = sum - nums[i];
        //                 }
        //                 else
        //                 {
        //                     sum = sum + nums[i];
        //                 }
        //             }
        //             return sum;
        //         }
        //         else
        //         {
        //             if(nums[positive_index] >= -nums[positive_index-1])
        //             {
        //             for(int i = 0; i < positive_index-1; i++)
        //             {
        //                 sum = sum - nums[i];
        //             }
        //             sum = sum + nums[positive_index-1];
        //             for(int i = positive_index; i < n; i++)
        //             {
        //                 sum = sum + nums[i];
        //             }
        //             return sum;
        //             }
        //             else
        //             {
        //                 for(int i = 0; i <= positive_index;i++)
        //                 {
        //                     sum = sum - nums[i];
        //                 }
        //                 for(int i = positive_index+1; i < n; i++)
        //                 {
        //                     sum = sum + nums[i];
        //                 }
        //                 return sum;
        //             }

        //         }
        //     }
        // }
        // return -1;
    }