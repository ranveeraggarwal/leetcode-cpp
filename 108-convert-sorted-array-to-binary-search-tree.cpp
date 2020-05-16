#include "stdafx.h"

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        if (nums.size() == 0)
            return NULL;
        return helper(nums, 0, nums.size() - 1);
    }

    TreeNode *helper(vector<int> &nums, int l, int r)
    {
        int rIndex = (l + r + 1) / 2;
        TreeNode *root = new TreeNode(nums[rIndex]);
        if (l != r)
        {
            if (rIndex - 1 >= l)
                root->left = helper(nums, l, rIndex - 1);
            if (rIndex + 1 <= r)
                root->right = helper(nums, rIndex + 1, r);
        }
        return root;
    }
};