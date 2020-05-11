#include "stdafx.h"

class Solution
{
    unordered_set<char> leftBrackets = {'(', '[', '{'};
    unordered_set<char> rightBrackets = {')', ']', '}'};

public:
    bool isValid(string s)
    {
        stack<char> bracketBalancer;
        for (char c : s)
        {
            if (!bracketBalancer.empty())
            {
                char t = bracketBalancer.top();
                if ((c == ')' && t == '(') || (c == ']' && t == '[') || (c == '}' && t == '{'))
                {
                    bracketBalancer.pop();
                    continue;
                }
                else if (leftBrackets.count(t) && rightBrackets.count(c))
                    return false;
            }
            bracketBalancer.push(c);
        }
        if (bracketBalancer.empty())
            return true;
        else
            return false;
    }
};