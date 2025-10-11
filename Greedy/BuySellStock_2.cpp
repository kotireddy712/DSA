// 1. The Greedy idea is to capture every small profit opportunity

// 2. So, instead of trying to find big peaks and valleys,we just collect every small increase(i,i+1).
    
    
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        //* Sum Up all upward changes... add up.. to profit..
        int profit = 0;
        for(int i = 0; i < n-1; i++)
        {
            if(prices[i] < prices[i+1])
            {
                profit = profit + (prices[i+1]-prices[i]);
            }
        }
        return profit;
    }