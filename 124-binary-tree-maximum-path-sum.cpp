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
    int vmax;

public:
    int maxPathSum(TreeNode *root)
    {
        vmax = INT_MIN;
        subPath(root);
        return vmax;
    }

    int subPath(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int val = root->val;
        int left = subPath(root->left);
        int right = subPath(root->right);
        if (left >= 0 && right >= 0)
        {
            vmax = max(vmax, left + right + val);
            return max(left, right) + val;
        }
        else if (left >= 0)
        {
            vmax = max(vmax, left + val);
            return left + val;
        }
        else if (right >= 0)
        {
            vmax = max(vmax, right + val);
            return right + val;
        }
        else
        {
            vmax = max(vmax, val);
            return val;
        }
    }
};