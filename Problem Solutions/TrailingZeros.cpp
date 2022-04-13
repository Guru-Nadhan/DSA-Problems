// https://practice.geeksforgeeks.org/problems/trailing-zeroes-in-factorial5134/1

// Brute force- calculate factorial of a no. and divide by 10 and see remainder to calculate the trailing zeros.
// But factorial of nos > 20 yeilds huge value which leads to integer overflow.
// So, Here, we use formula for zeros in a factorial. Trailing zeros is made by powers of 2 and 5.
// 2 always occurs more than 5. So, if we calculate the multiples of 5 occuring in the given input, we can find the trailing zeros
// formula is zeros=(N/5)+(N/5^2)+(N/5^3)+(N/5^4).....until denominator is<=N
// TC is O(logN) to the base 5. SC- O(1)
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int trailingZeroes(int n)
    {
        // Write Your Code here
        int denominator = 5, zeros = 0;
        while (n >= denominator)
        {
            zeros += n / denominator;
            denominator *= 5;
        }
        return zeros;
    }
};
