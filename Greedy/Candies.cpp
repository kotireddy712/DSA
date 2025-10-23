// Question  ::  135 - https://leetcode.com/problems/candy/description/ 

//     * Here main idea was to take two passes (forward - Pass :: Check with previous && Backward-Pass :: Check with Next ?? maxi)
    
    int candy(vector<int>& ratings) 
    {
        int n = ratings.size(); //** No.of.Students.
        vector<int> candies(n,1);
        // ** Forward - Pass with chekcing with previous..
        for(int i = 1; i < n; i++)
        {
            if( ratings[i-1] < ratings[i] )
            {
                candies[i] = candies[i-1] + 1;
            }
        }
        // ** Backward Pass with checking with next
        for(int i = n-2; i >= 0; i--)
        {
            if( ratings[i] > ratings[i+1] )
            {
                candies[i] = max(candies[i],candies[i+1]+1);
            }
        }
        int sum = 0;
        for(int i = 0; i < n; i++)
        {
            sum = sum + candies[i];
        }
        return sum;
    }