#include "stdafx.h"

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        int b = prices[0];
        int profit = 0;
        int currPrice;
        for (int i = 1; i < prices.size(); i++)
        {
            currPrice = prices[i];
            profit = max(profit, currPrice - b);
            if (currPrice < b)
                b = currPrice;
        }
        return profit;
    }
};