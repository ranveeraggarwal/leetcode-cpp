#include "stdafx.h"

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_map<char, int> lastSeenIndex;
        int cursor = 0, maxLength = 0;
        char currentCharacter;
        for (int i = 0; i < s.size(); i++)
        {
            currentCharacter = s[i];
            auto it = lastSeenIndex.find(currentCharacter);
            if (it == lastSeenIndex.end() || it->second < cursor)
            {
                maxLength = max(maxLength, i - cursor + 1);
            }
            else
            {
                cursor = it->second + 1;
            }
            lastSeenIndex[currentCharacter] = i;
        }

        return maxLength;
    }
};