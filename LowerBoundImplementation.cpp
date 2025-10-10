// Modification Of Binary Search ..

// Finding element >=x if x not found next greatest of least x...

// Returns index of array /.

// i) if all Elements in nums < x ; then it retruns nums.size() ...

int BinarySearch(vector<int>& nums,int x)
{
    int low = 0;
    int high = nums.size();
    while(low < high)
    {
        int mid = low + (low-high)/2 //** used for nice representation.. */
        if(nums[mid] < x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }

}

// This Algo.. same as in-built fucntion of lower bound..

// auto it = lower_bound(nums.begin(),nums.end(),x);
// int index  = it - nums.begin();

// For set ::
// -------
// set<int> s;
// auto it1 = s.lower_bound(x);