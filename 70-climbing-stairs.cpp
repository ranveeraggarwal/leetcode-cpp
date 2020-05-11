#include "stdafx.h"

class Solution
{
public:
    int climbStairs(int n)
    {
        int last = 1;
        int secondLast = 1;
        int curr = 1;
        for (int i = 2; i <= n; i++)
        {
            curr = last + secondLast;
            secondLast = last;
            last = curr;
        }
        return curr;
    }
};