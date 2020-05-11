#include "stdafx.h"

class Solution
{
public:
    string sortString(string &s)
    {
        int chars[26] = {0};
        for (char c : s)
        {
            chars[c - 'a']++;
        }
        string result = "";
        for (int i = 0; i < 26; i++)
        {
            result += (char)('a' + i);
            result += (char)('0' + chars[i]);
        }
        return result;
    }

    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        vector<vector<string>> groups;
        unordered_map<string, int> stringGroups;
        for (string &s : strs)
        {
            string sortedString = sortString(s);
            auto stringGroup = stringGroups.find(sortedString);
            if (stringGroup == stringGroups.end())
            {
                vector<string> newGroup;
                newGroup.push_back(s);
                groups.push_back(newGroup);
                stringGroups.insert(make_pair(sortedString, groups.size() - 1));
            }
            else
            {
                groups[stringGroup->second].push_back(s);
            }
        }
        return groups;
    }
};