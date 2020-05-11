#include "stdafx.h"

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int n = strs.size();
        if (n == 0)
            return "";
        string prefix = strs[0];
        for (int i = 1; i < n; i++)
        {
            if (prefix == "")
                break;
            for (int j = 0; j < prefix.size(); j++)
            {
                if (strs[i][j] != prefix[j])
                {
                    prefix = prefix.substr(0, j);
                    break;
                }
            }
        }
        return prefix;
    }
};