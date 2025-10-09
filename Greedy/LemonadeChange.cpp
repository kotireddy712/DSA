// Question Link :: 860 - https://leetcode.com/problems/lemonade-change/description/

// 1. Greeady Comes here to use 10's possibile to customers; since 5's change is more versatile and useful.so, dont waste it unnesccarily..

    bool lemonadeChange(vector<int>& bills) 
    {
        int n = bills.size();
        unordered_map<int,int> freq;
        for(int i = 0; i < n; i++)
        {
           if(bills[i] == 5)
           {
                freq[5]++;
           }
          else if(bills[i] == 10)
           {
                freq[10]++;
                if(freq[5] == 0)
                {
                    return false;
                }
                freq[5]--;
           }
          else if(bills[i] == 20)
           {
                freq[20]++;
                if( freq[5] == 0 || (freq[10] == 0 && freq[5] < 3) )
                {
                    return false;
                }
                //** SEE HERE, TRY TO USE UP 10'S-Coins they are not needed but dont waste 5's Coins its used in future. */
                if(freq[10] > 0)
                {
                    freq[10]--;
                    freq[5]--;
                }
                else
                {
                    freq[5] = freq[5] - 3;
                }
           }
        }
        return true;
    }