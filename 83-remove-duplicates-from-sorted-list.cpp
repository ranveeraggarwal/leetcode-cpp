#include "stdafx.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *cursor = head;
        int current = cursor->val;
        while (cursor->next != NULL)
        {
            if (cursor->next->val == current)
            {
                cursor->next = cursor->next->next;
            }
            else
            {
                current = cursor->next->val;
                cursor = cursor->next;
            }
        }
        return head;
    }
};
