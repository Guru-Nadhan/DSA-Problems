// https://practice.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1/
// brute force is using i and j loop to calculate every subarray sum. TC- O(N^2) and SC- O(1)
// Here, TC- O(N),SC- O(N)
class Solution
{
public:
    bool subArrayExists(int arr[], int n)
    {
        unordered_map<int, int> mp;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            mp[sum]++;
            if (sum == 0)
                return true;
            if (mp[sum] > 1)
                return true;
        }
        return false;
    }
};

// exactly the same solution but with prefix array
class Solution
{
public:
    bool subArrayExists(int arr[], int n)
    {
        unordered_map<int, int> mp;
        int prefix[n];
        prefix[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            prefix[i] = arr[i] + prefix[i - 1];
        }
        for (int i = 0; i < n; i++)
        {
            if (prefix[i] == 0)
            {
                return true;
            }
            if (mp.find(prefix[i]) != mp.end())
            {
                return true;
            }
            mp[prefix[i]]++;
        }
        return false;
    }
};