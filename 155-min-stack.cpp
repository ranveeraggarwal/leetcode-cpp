#include "stdafx.h"

class MinStack
{
public:
    /** initialize your data structure here. */
    stack<int> nums;

    MinStack()
    {
    }

    void push(int x)
    {
        int minSoFar = x;
        if (!nums.empty())
        {
            minSoFar = min(nums.top(), x);
        }
        nums.push(x);
        nums.push(minSoFar);
    }

    void pop()
    {
        nums.pop();
        nums.pop();
    }

    int top()
    {
        int x = nums.top();
        nums.pop();
        int y = nums.top();
        nums.push(x);
        return y;
    }

    int getMin()
    {
        return nums.top();
    }
};