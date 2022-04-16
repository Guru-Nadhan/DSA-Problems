// https://leetcode.com/problems/subarray-sum-equals-k/
// similar to the subArrayWith0Sum.cpp sum

// use prefix array and map.
// suppose we have an array as arr[]: [1,2,3,4,5] and k = 9
// so, our answer will be '2' i.e (2 + 3 + 4 and 4 + 5)
// index :   0, 1, 2, 3,  4
//   arr[]: [1, 2, 3, 4,  5]
// prefix[]:[1, 3, 6, 10, 15]
//           ↑         ↑
// 1) if we see our prefix sum at index 3 then it is 10 and also prefix sum at index 0 is 1
// so, we can say that from index 0 to 3 our prefix sum increases from 1 to 10, right,
// 2) So on putting a question, HOW MUCH ? means how much our sum increase from index 0 to index 3
// then, we simply say, we find the difference between these two sums i.e (10 - 1) is the sum that increases from index 0 to 3.
// 3) Now, if we will see then we find out (10 - 1) is nothing but our 'k' that is 9.
// 4) So, we find out, that a subarray may also exist if this particular condition satisified, i.e
//     (prefix[i] - k) should exist in our map,
// Time Complexity --> O(n) where n is the size of the array
// Space Complexity --> O(n) we are using unordered map from

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        int prefix[nums.size()], ans = 0;
        unordered_map<int, int> mp;
        prefix[0] = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            prefix[i] = nums[i] + prefix[i - 1];
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (prefix[i] == k)
                ans++;
            if (mp.find(prefix[i] - k) != mp.end())
            {
                ans += mp[prefix[i] - k];
            }
            mp[prefix[i]]++;
            // cout<<prefix[i]<<" "<<mp[prefix[i]]<<endl;
        }
        return ans;
    }
};