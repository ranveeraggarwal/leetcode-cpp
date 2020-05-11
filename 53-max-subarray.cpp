#include "stdafx.h"

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int maxSum = nums[0], currSum = nums[0], tempSum;
        for (int i = 1; i < nums.size(); i++)
        {
            if (currSum < 0)
            {
                currSum = max(currSum, nums[i]);
            }
            else
            {
                tempSum = currSum + nums[i];
                if (tempSum > 0)
                    currSum = tempSum;
                else
                    currSum = 0;
            }

            maxSum = max(currSum, maxSum);
        }
        return maxSum;
    }
};