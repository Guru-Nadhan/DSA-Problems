// https://leetcode.com/problems/longest-common-prefix/
// BruteForce Approach:
// compare each pair of strings one by one and update the ans. TC- O(N*M) where N is no of strings and M is max length of a string.
// Optimised Approach:
// sort the array of strings and just compare the first and last string. TC- O(Nlog N) for sorting. SC-O(1)
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int n = strs.size();
        string ans = "";
        sort(strs.begin(), strs.end());
        for (int i = 0; i < strs[0].length(); i++)
        {
            if (strs[0][i] == strs[n - 1][i])
                ans.push_back(strs[0][i]);
            else
                break;
        }
        return ans;
    }
};