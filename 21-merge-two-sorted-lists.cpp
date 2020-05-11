#include "stdafx.h"

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        // head of the list to be returned
        ListNode *head = new ListNode(0);
        ListNode *cursor = head;
        while (l1 != NULL && l2 != NULL)
        {
            if (l1->val > l2->val)
            {
                cursor->next = l2;
                l2 = l2->next;
                cursor->next->next = NULL;
            }
            else
            {
                cursor->next = l1;
                l1 = l1->next;
                cursor->next->next = NULL;
            }
            cursor = cursor->next;
        }
        if (l1 != NULL)
        {
            cursor->next = l1;
        }
        if (l2 != NULL)
        {
            cursor->next = l2;
        }
        return head->next;
    }
};