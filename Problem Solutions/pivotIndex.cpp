// https://leetcode.com/problems/find-pivot-index/
// Brute force, i loop to parse the array and a j loop inside to calculate left sum and a k loop inside to calculate right sum. (j=0;j<i;j++) and (k=i+1;k<n;k++). TC- O(N^2) and SC- O(1)
// another approach is to have separate array for sum of elems from left and another array for sum of elems from right. and if the sum is same in any index, then that index is the pivot. TC- O(3N) and SC-O(2N)
// Here, TC- O(N) and SC- O(1)
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();
        int total = 0;
        for (int i = 0; i < n; i++)
        {
            total += nums[i];
        }
        int left = 0, right = total;
        for (int i = 0; i < n; i++)
        {
            right = right - nums[i];
            if (left == right)
            {
                return i;
            }
            left += nums[i];
        }
        return -1;
    }
};