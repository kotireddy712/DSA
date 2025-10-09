// Question Link - 409 - :: https://leetcode.com/problems/longest-palindrome/description/

// 1. Take all even frequency charcters all add up;
// 2. When oddd freq charcter comes reduce 1 and continue..
// 3. if atleast one add character exsists then finally add (+1) to count and then return ..

    int longestPalindrome(string s) 
    {
        int n = s.size();
        unordered_map<char,int> M;
        for(int i = 0; i < n; i++)
        {
            M[s[i]]++;
        }
        int count = 0;
        bool odd_exsist=false;
        for(auto i : M)
        {
            // if(i.second % 2 == 0)
            // {
            //     count = count + i.second;
            // }
            // else
            // {
            //     if(maxi < i.second)
            //     {
            //         if(maxi != 0)
            //         {
            //         count = count + ( maxi - 1 );
            //         }
            //         maxi = i.second;
            //     }
            //     else
            //     {
            //         count = count + (i.second - 1);
            //     }
            // }
            count = count +( (i.second)/2 ) * 2;
            if(i.second % 2 == 1)
            {
                odd_exsist = true;
            }
        }
        if(odd_exsist)
        {
            count = count + 1;
        }
       // count = count + maxi;
        return count;
    }