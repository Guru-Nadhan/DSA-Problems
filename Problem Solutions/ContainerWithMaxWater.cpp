// https://leetcode.com/problems/container-with-most-water/
// Brute Force:
// use i and j loop to calculate area of each pair and then get max area. TC- O(N^2)
// Optimised approach:
// use low and high pointer. find area between low and high and compare with max area.
// then change the minimum side pointer and repeat.
class Solution
{
public:
    int maxArea(vector<int> &nums)
    {
        int n = nums.size();
        int low = 0, high = n - 1;
        int max_area = INT_MIN;
        int area;
        while (low < high)
        {
            area = (min(nums[low], nums[high])) * (high - low);
            if (area > max_area)
            {
                max_area = area;
            }
            if (nums[low] < nums[high])
                low++;
            else
                high--;
        }
        return max_area;
    }
};