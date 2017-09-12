/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

void addone(ListNode* l)
{
    while (l->val >= 10)
    {
        l->val %= 10;
        if (NULL == l->next)
        {
            ListNode *next = new ListNode(1);
            l->next = next;
        }
        else
        {
            l->next->val += 1;
        }
        l = l->next;
    }
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = l1;
        while (NULL != l1 && NULL != l2)
        {
            l1->val = l1->val + l2->val;
            ListNode *tmp = l1;
            addone(tmp);
            l1 = l1->next;
            l2 = l2->next;
        }

        if (NULL != l2)
        {
            ListNode *tmp = p;
            while (NULL != tmp->next)
            {
                tmp = tmp->next;
            }
            tmp->next = l2;
        }
        
        return p;
    }
};
