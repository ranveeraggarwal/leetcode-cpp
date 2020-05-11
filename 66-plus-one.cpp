#include "stdafx.h"

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        vector<int> result;
        int carry = 1, digSum = 0;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            digSum = digits[i] + carry;
            result.push_back(digSum % 10);
            carry = digSum / 10;
        }
        if (carry > 0)
        {
            result.push_back(carry);
        }
        std::reverse(result.begin(), result.end());
        return result;
    }
};