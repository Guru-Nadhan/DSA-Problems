// https://leetcode.com/problems/sort-colors/
// Approach 1: we could just use STL sort. TC- O(NlogN)
// Approach 2: we could just count no of zeros, ones and twos and then replace them in the array. TC- O(2N)

// Approach 3: Here, we are using the dutch flag algorithm. TC- O(N)
// we have low pointer and high pointer for 0 and 2 resprctively.
// the mid pointer traverses the array and we swap values with low or high accordingly
class Solution
{
public:
    void swap(int &a, int &b)
    {
        int t = a;
        a = b;
        b = t;
    }
    void sortColors(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, mid = 0, high = n - 1;
        while (mid <= high)
        {
            if (nums[mid] == 0)
                swap(nums[mid++], nums[low++]);
            else if (nums[mid] == 1)
                mid++;
            else
                swap(nums[mid], nums[high--]);
        }
    }
};