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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> result;
        if (root != NULL)
        {
            stack<TreeNode *> tracker;
            while (root != NULL)
            {
                tracker.push(root);
                root = root->left;
            }

            while (!tracker.empty())
            {
                root = tracker.top();
                tracker.pop();
                result.push_back(root->val);

                root = root->right;
                while (root != NULL)
                {
                    tracker.push(root);
                    root = root->left;
                }
            }
        }
        return result;
    }
};