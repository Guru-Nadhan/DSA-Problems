// Leetcode problem link- https://leetcode.com/problems/two-sum/
// Bruteforce: i,j for loop and find pair sum. TC-O(N^2) SC- O(1)
// Another approach: sort using STL sort and then use 2 pointer method, one at beginning and another at end. TC-O(NlogN)
// Here we use hashmap method. Time complexity- O(N), Space complexity- O(N)
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            if (mp.find(target - nums[i]) != mp.end())
            {
                return {mp[target - nums[i]], i};
            }
            mp.insert({nums[i], i});
        }
        return {-1, -1};
    }
};