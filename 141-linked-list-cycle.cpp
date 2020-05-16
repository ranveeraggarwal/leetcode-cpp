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
    bool hasCycle(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        while (true)
        {
            if (fast == NULL || fast->next == NULL)
                return false;
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        // this will never happen though
        return false;
    }
};