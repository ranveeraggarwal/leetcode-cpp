#include "stdafx.h"

class Solution
{
    vector<uint32_t> ones;
    bool initialized = false;

public:
    int hammingWeight(uint32_t n)
    {
        if (!initialized)
        {
            for (int i = 0; i < 32; i++)
            {
                ones.push_back(1 << i);
            }
        }
        int count = 0;
        for (int i = 0; i < 32; i++)
        {
            if (n & ones[i])
            {
                count++;
            }
        }
        return count;
    }
};