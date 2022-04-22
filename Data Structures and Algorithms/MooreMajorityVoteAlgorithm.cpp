// https://leetcode.com/problems/majority-element/
// Brute Force:
// We can use i loop and j loop from 0 to N to count each elements occurence and find majority. but TC will be O(N^2)
// Another Approach:
// we can also use map to count the occurence. TC will be O(N) and SC will be O(N).
// Moore Majority Algorithm: TC-O(N) and SC(1)
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        int majority_index = 0, count = 1;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] == nums[majority_index])
                count++;
            else
                count--;
            if (count == 0)
            {
                majority_index = i;
                count = 1;
            }
        }
        //  In this leetcode sum, it is given that Majority element always exists.
        //  If the Majority element may or may not exist, then write the following extra lines of code

        // int final_count=0;
        // for(int i=0;i<n;i++){
        //     if(nums[i]==nums[majority_index])
        //         final_count++;
        // }
        // if(final_count>n/2)
        //     return nums[majority_index];
        // else
        //     return -1;
        return nums[majority_index];
    }
};