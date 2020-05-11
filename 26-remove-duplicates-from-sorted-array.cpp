#include "stdafx.h"

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int pStart = 1, pMove = 1, current = nums[0];
        while (pMove < nums.size())
        {
            if (nums[pMove] != current)
            {
                nums[pStart] = nums[pMove];
                current = nums[pMove];
                pStart++;
            }
            pMove++;
        }
        return pStart;
    }
};