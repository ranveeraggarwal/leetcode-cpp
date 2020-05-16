#include "stdafx.h"

class Solution
{
    uint32_t ones[32];
    bool initialized = false;

public:
    uint32_t reverseBits(uint32_t n)
    {
        if (!initialized)
        {
            for (int i = 0; i < 32; i++)
            {
                ones[i] = 1 << i;
            }
        }
        uint32_t reversed = 0;
        for (int i = 31; i >= 0; i--)
        {
            if (ones[i] & n)
            {
                reversed += 1 << (31 - i);
            }
        }
        return reversed;
    }
};