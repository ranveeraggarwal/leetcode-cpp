#include "stdafx.h"

class Solution
{
public:
    string countAndSay(int n)
    {
        string result = "1";
        string current;
        for (int i = 2; i <= n; i++)
        {
            current = "";
            char c = result[0];
            int count = 1;
            char charCount;
            for (int j = 1; j < result.size(); j++)
            {
                if (result[j] != c)
                {
                    charCount = count + '0';
                    current += charCount;
                    current += c;
                    c = result[j];
                    count = 1;
                }
                else
                {
                    count++;
                }
            }
            charCount = count + '0';
            current += charCount;
            current += c;
            result = current;
        }
        return result;
    }
};