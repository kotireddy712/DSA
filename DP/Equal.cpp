// i) “Add 1/2/5 to all except one person” ≡ “Reduce that one person by 1/2/5”.

// ii) ✅ Correct logic
// You compute how many steps of 5, 2, and 1 are needed for each person to reach the minimum (or near-minimum {there come's :: j loop from 0 to 4 (max.remainder's possibile when divided by ""5"")}) value.

int equal(vector<int> arr) 
{
    int n = arr.size();
    auto it = min_element(arr.begin(),arr.end());
    int final = INT_MAX;
    for(int j = 0; j <= 4; j++)
    {
        int count = 0;
        int target = (*it) - j;
        for(int i = 0; i < n; i++)
        {
            int diff = arr[i] - target;
            if(diff == 0)
            {
                continue;
            }
            int a = diff/5;
            int r1 = diff%5;
            int b = r1/2;
            int r2 = r1%2;
            int c = r2;
            count = count + a + b + c;  
            //arr[i] = arr[i] - diff;
        }
        final = min(final,count);
    }
    return final;
}