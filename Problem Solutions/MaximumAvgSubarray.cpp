// https://leetcode.com/problems/maximum-average-subarray-i/
// Brute Force Approach:
// find avg of all contiguous k elems using i and j loop. TC- O(N*K), where N-size of array and K-given size of subarray.
// Here, we are using sliding window technique. TC- O(N)
class Solution
{
public:
    double findMaxAverage(vector<int> &nums, int k)
    {
        int n = nums.size();
        double sum = 0, max_avg;
        for (int i = 0; i < k; i++)
        {
            sum += nums[i];
        }
        max_avg = sum / k;
        int i = 0, j = k;
        while (j < n)
        {
            sum = sum - nums[i++] + nums[j++];
            if ((sum / k) > max_avg)
                max_avg = sum / k;
        }
        return max_avg;
    }
};