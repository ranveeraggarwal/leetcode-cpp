#include "stdafx.h"

class Solution
{
public:
    int titleToNumber(string s)
    {
        int acc = 0;
        for (auto &c : s)
        {
            acc = (acc * 26) + (int)(c - 'A');
        }
        return acc;
    }
};