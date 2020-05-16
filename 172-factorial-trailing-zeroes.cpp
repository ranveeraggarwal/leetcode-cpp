#include "stdafx.h"

class Solution
{
public:
    int trailingZeroes(int n)
    {
        long cf = 5;
        int nzero = 0;
        while (true)
        {
            if (n / cf == 0)
                break;
            nzero += n / cf;
            cf *= 5;
        }
        return nzero;
    }
};