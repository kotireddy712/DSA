sort
(
    vec.begin(),vec.end(),
    [](vector<int>& a, vector<int>& b) // [a,b]...
    {
        if(a[0]==b[0])
        {
            return a[1]<b[1]; // if-first avlue same, then sort ascending on second
        }
        return a[0]<b[0]; // sort ascending on first
    }
);