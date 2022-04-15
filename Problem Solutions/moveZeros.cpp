// https://leetcode.com/problems/move-zeroes/
// Brute approach is to copy the non zero elements to another temp array
// and then fill the rest with zero and copy the temp array to the original array. But the SC will be O(N).
// In this method, the TC is O(N), SC is O(1)
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int nonZeroCount = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[nonZeroCount++] = nums[i];
            }
        }
        while (nonZeroCount < nums.size())
        {
            nums[nonZeroCount++] = 0;
        }
    }
};