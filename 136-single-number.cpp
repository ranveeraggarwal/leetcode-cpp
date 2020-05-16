#include "stdafx.h"

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int singleNum = 0;
        for (auto &num : nums)
        {
            singleNum ^= num;
        }
        return singleNum;
    }
};