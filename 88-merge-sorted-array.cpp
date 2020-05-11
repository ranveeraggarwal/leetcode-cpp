#include "stdafx.h"

class Solution
{
public:
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m + n;
        m--;
        n--;
        while (m >= 0 && n >= 0)
        {
            i--;
            if (nums1[m] > nums2[n])
            {
                nums1[i] = nums1[m];
                m--;
            }
            else
            {
                nums1[i] = nums2[n];
                n--;
            }
        }
        while (n >= 0)
        {
            i--;
            nums1[i] = nums2[n];
            n--;
        }
    }
};