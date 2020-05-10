#include "stdafx.h"

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        // properties of the final substring
        int start = 0, maxlen = 0;
        // temporary variables
        int leftCursor, rightCursor, currentLength;
        for (int i = 0; i < n; i++)
        {
            // odd-length palindromes
            leftCursor = i;
            rightCursor = i;
            while (leftCursor >= 0 && rightCursor < n && s[leftCursor] == s[rightCursor])
            {
                leftCursor--;
                rightCursor++;
            }
            currentLength = rightCursor - leftCursor - 1;
            if (currentLength > maxlen)
            {
                maxlen = currentLength;
                start = leftCursor + 1;
            }

            // even-length palindromes
            // ToDo: code repetition; could be made into a function
            leftCursor = i;
            rightCursor = i + 1;
            while (leftCursor >= 0 && rightCursor < n && s[leftCursor] == s[rightCursor])
            {
                leftCursor--;
                rightCursor++;
            }
            currentLength = rightCursor - leftCursor - 1;
            if (currentLength > maxlen)
            {
                maxlen = currentLength;
                start = leftCursor + 1;
            }
        }

        return s.substr(start, maxlen);
    }
};