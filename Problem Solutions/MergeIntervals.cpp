// https://leetcode.com/problems/merge-intervals/
// TC- O(NlogN) for sorting the intervals of size N
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> sol;
        int j = 0;
        sol.push_back(intervals[0]);
        for (int i = 1; i < n; i++)
        {
            if (sol[j][1] >= intervals[i][0])
            {
                sol[j][1] = max(sol[j][1], intervals[i][1]);
            }
            else
            {
                sol.push_back(intervals[i]);
                j++;
            }
        }
        return sol;
    }
};