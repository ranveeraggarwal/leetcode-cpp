#include "stdafx.h"

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // vector of size 2
        vector<int> result(2);
        // here we store the result of subtracting each number from the target
        unordered_map<int, int> diffMap;
        for (int i = 0; i < nums.size(); i++)
        {
            diffMap[target - nums[i]] = i;
        }
        // lets try to find a number in the array in our diffMap
        for (int i = 0; i < nums.size(); i++)
        {
            if (diffMap.count(nums[i]) > 0 && diffMap[nums[i]] != i)
            {
                result = {diffMap[nums[i]], i};
                // sorting, since the lower index needs to be returned first
                sort(result.begin(), result.end());
                return result;
            }
        }
        return result;
    }
};