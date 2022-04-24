// https://leetcode.com/problems/binary-search/
// TC- O(log N), SC- O(1)
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int beg = 0, end = n - 1, mid;
        while (beg <= end)
        {
            mid = (beg + end) / 2;
            if (target == nums[mid])
                return mid;
            else if (target < nums[mid])
                end = mid - 1;
            else
                beg = mid + 1;
        }
        return -1;
    }
};