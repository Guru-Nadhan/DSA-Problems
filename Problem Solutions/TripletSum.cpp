// https://leetcode.com/problems/3sum/
// TC- O(M*N^2), SC- O(M) where M is the size of ans vector and N is size of the input vector
// First sort the array, and then use a for loop and 2 pointer method to find triplet sum.
// Hard part for me was to neglect the duplicates in the answer
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        if (nums.size() < 3)
        {
            return {};
        }
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int low = i + 1, high = nums.size() - 1;
            while (low < high)
            {
                bool flag = false;
                int sum = nums[i] + nums[low] + nums[high];
                if (sum == 0)
                {
                    for (int j = 0; j < ans.size(); j++)
                    {
                        if (ans[j][0] == nums[i] && ans[j][1] == nums[low] && ans[j][2] == nums[high])
                        {
                            flag = true;
                            // cout<<ans[j][0]<<" "<<ans[j][1]<<" "<<ans[j][2]<<endl;
                        }
                    }
                    if (flag == false)
                    {
                        ans.push_back({nums[i], nums[low], nums[high]});
                    }
                    low++;
                }
                else if (sum < 0)
                {
                    low++;
                }
                else
                    high--;
            }
        }
        return ans;
    }
};

// Optimised approach from online solution. TC is O(N^2)
// just checks and skips the repetitions in the i loop and low,high pointers
class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++)
        {
            int target = 0 - nums[i];

            int low = i + 1;
            int high = n - 1;

            while (low < high)
            {
                int sum = nums[low] + nums[high];

                if (sum < target)
                    low++;
                else if (sum > target)
                    high--;
                else
                {
                    vector<int> temp = {nums[i], nums[low], nums[high]};
                    res.push_back(temp);
                    // skipping repetitions in low side
                    while (low < high && nums[low] == temp[1])
                        low++;
                    // skipping repetitions in high side
                    while (low < high && nums[high] == temp[2])
                        high--;
                }
            }
            // skipping repetitions in the main i loop
            while (i < n - 1 && nums[i] == nums[i + 1])
                i++;
        }

        return res;
    }
};