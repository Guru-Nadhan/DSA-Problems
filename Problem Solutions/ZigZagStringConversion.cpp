// https://leetcode.com/problems/zigzag-conversion/
// TC- O(N), SC- O(R) where N is length of string and R is no of rows

class Solution
{
public:
    string convert(string s, int rows)
    {
        int n = s.length();
        // for edge case when rows = 1
        if (rows == 1)
        {
            return s;
        }
        string temp[rows];
        int count = 0;
        bool front = true;
        for (int i = 0; i < n; i++)
        {
            if (front)
            {
                // cout<<"front "<<count<<"\t"<<temp[0]<<"\t"<<temp[1]<<"\t"<<temp[2]<<endl;
                temp[count++].push_back(s[i]);
                if (count == rows)
                {
                    front = false;
                    count -= 2;
                }
            }
            else
            {
                // cout<<"rever "<<count<<"\t"<<temp[0]<<"\t"<<temp[1]<<"\t"<<temp[2]<<endl;
                temp[count--].push_back(s[i]);
                if (count < 0)
                {
                    front = true;
                    count += 2;
                }
            }
        }
        string ans = "";
        for (int i = 0; i < rows; i++)
        {
            ans += temp[i];
        }
        return ans;
    }
};