#include "stdafx.h"

/*
// Definition for a Node.
*/
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == NULL)
            return root;
        queue<pair<Node *, int>> q;
        q.push({root, 0});

        int level = 0;
        Node *cur = root, *top;

        while (!q.empty())
        {
            top = q.front().first;

            if (root != top)
            {
                if (q.front().second != level)
                {
                    level = q.front().second;
                    cur = top;
                }
                else
                {
                    cur->next = top;
                    cur = top;
                }
            }

            q.pop();

            if (top->left != NULL)
                q.push({top->left, level + 1});
            if (top->right != NULL)
                q.push({top->right, level + 1});
        }

        return root;
    }
};