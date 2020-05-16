#include "stdafx.h"

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 3);
        for (int i = 3; i < n + 3; i++)
        {
            dp[i] = max(dp[i - 1], max(dp[i - 2] + nums[i - 3], dp[i - 3]));
        }
        return dp[n + 2];
    }
};