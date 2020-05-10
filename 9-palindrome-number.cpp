#include "stdafx.h"

class Solution
{
public:
    bool isPalindrome(int x)
    {
        // crappy if check to retain elegance of the algorithm
        if (x < 0 || (x > 0 && x % 10 == 0))
            return false;
        // lets build half a reverse number
        int y = 0;
        while (y <= x)
        {
            // even length palindrome
            if (y == x)
                return true;
            y = 10 * y + x % 10;
            x = x / 10;
        }
        // odd length palindrome needs an extra check
        if (y / 10 == x)
            return true;
        return false;
    }
};