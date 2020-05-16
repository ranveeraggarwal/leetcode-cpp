#include "stdafx.h"

class Solution
{
    bool sanitizeChar(char &c)
    {
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            if (c < 'a')
                c = (char)(c + 'a' - 'A');
            return true;
        }
        else if (c >= '0' && c <= '9')
            return true;
        return false;
    }

public:
    bool isPalindrome(string s)
    {
        int pStart = 0, pEnd = s.size() - 1;
        char cStart, cEnd;
        while (pStart < pEnd)
        {
            cStart = s[pStart];
            cEnd = s[pEnd];
            if (!sanitizeChar(cStart))
            {
                pStart++;
                continue;
            }
            if (!sanitizeChar(cEnd))
            {
                pEnd--;
                continue;
            }
            if (cStart != cEnd)
                return false;
            pStart++;
            pEnd--;
        }
        return true;
    }
};