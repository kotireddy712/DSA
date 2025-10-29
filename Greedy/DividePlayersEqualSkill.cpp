// Question :: 2491 -  https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/?utm_source=chatgpt.com

    long long dividePlayers(vector<int>& skill) 
    {
        //** Main - Idea :: All team's have same sum possibile :: ALWAYS FIRST AND LAST COMB0 ..  ** 
        int n = skill.size();
        if( n % 2 != 0 )
        {
            return -1;
        }
        sort(skill.begin(),skill.end());
        int fix_equal_sum = skill[0] + skill[n-1];
        long long int result = 0;
        for(int i = 0; i < (n/2); i++)
        {
            if( skill[i] + skill[n-i-1] != fix_equal_sum )
            {
                return -1;
            }
            else
            {
                result = result + ( skill[i] * skill[n-i-1] );
            }
        }
        return result;
    }