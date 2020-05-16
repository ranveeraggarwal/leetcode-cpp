#include "stdafx.h"

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int elem, count = 0;
        for (int num : nums)
        {
            if (count == 0)
            {
                elem = num;
                count++;
            }
            else
            {
                if (elem == num)
                    count++;
                else
                    count--;
            }
        }
        return elem;
    }
};