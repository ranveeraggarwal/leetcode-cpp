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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *travelA = headA, *travelB = headB;
        while (travelA != NULL && travelB != NULL)
        {
            travelA = travelA->next;
            travelB = travelB->next;
        }
        int dist = 0;
        bool isALonger = false;
        if (travelA == NULL)
        {
            isALonger = false;
            while (travelB != NULL)
            {
                dist++;
                travelB = travelB->next;
            }
        }
        else if (travelB == NULL)
        {
            isALonger = true;
            while (travelA != NULL)
            {
                dist++;
                travelA = travelA->next;
            }
        }
        travelA = headA;
        travelB = headB;
        if (isALonger)
        {
            while (dist--)
                travelA = travelA->next;
        }
        else
        {
            while (dist--)
                travelB = travelB->next;
        }

        while (travelA != travelB)
        {
            travelA = travelA->next;
            travelB = travelB->next;
        }
        return travelA;
    }
};