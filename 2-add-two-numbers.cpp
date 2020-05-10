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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0, sum;
        ListNode *head = new ListNode(-1);
        ListNode *cur = head;
        while (l1 != NULL && l2 != NULL)
        {
            sum = carry + l1->val + l2->val;
            ListNode *t = new ListNode(sum % 10);
            carry = sum / 10;

            cur->next = t;
            cur = t;

            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL)
        {
            sum = carry + l1->val;
            ListNode *t = new ListNode(sum % 10);
            carry = sum / 10;

            cur->next = t;
            cur = t;

            l1 = l1->next;
        }
        while (l2 != NULL)
        {
            sum = carry + l2->val;
            ListNode *t = new ListNode(sum % 10);
            carry = sum / 10;

            cur->next = t;
            cur = t;

            l2 = l2->next;
        }
        if (carry)
        {
            ListNode *t = new ListNode(carry);
            cur->next = t;
            cur = t;
        }
        return head->next;
    }
};