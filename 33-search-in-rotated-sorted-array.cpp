#include "stdafx.h"

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // find the pivot point using bianry search and then
        // binary search in the right segment.
        int n = nums.size();
        if (!n)
            return -1;
        int pivot = n - 1;
        int lo = 0, hi = n - 1, mid;
        while (lo < hi)
        {
            mid = (lo + hi) / 2;
            if ((mid > 0 && nums[mid] < nums[mid - 1]))
            {
                pivot = mid - 1;
                break;
            }
            if (mid < n - 1 && nums[mid] > nums[mid + 1])
            {
                pivot = mid;
                break;
            }
            if (nums[mid] >= nums[n - 1])
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid;
            }
        }
        if (target < nums[0] && target > nums[n - 1])
            return -1;

        if (target < nums[0])
        {
            lo = pivot + 1;
            hi = n - 1;
        }
        else
        {
            lo = 0;
            hi = pivot;
        }
        while (lo <= hi)
        {
            mid = (lo + hi) / 2;
            if (target == nums[mid])
                return mid;
            else if (target > nums[mid])
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        return -1;
    }
};
