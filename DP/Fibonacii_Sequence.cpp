 ** Space Optimised code ::

  int fib(int n) 
    {
        if(n <= 1)
        {
            return n;
        }
        int prev2 = 0;
        int prev = 1;
        int curri;
        for(int i = 2; i <= n; i++)
        {
            curri = prev + prev2;
            prev2 = prev;
            prev = curri;
        }
        return curri;
    }

    ** T.C we cant still reduce to O(logN)- By, "" Matrix Exponentation ..""