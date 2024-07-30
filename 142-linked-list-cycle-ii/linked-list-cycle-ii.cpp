/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* findStart(ListNode* slow, ListNode* fast)
    {
        while(slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
            if(fast == slow) return slow;
        }
        return slow;
    }
    ListNode *detectCycle(ListNode *head) {
        
        ListNode* slow(head);
        ListNode* fast(head);

        while(fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast) return findStart(head, fast);
        }

        return NULL;
    }
};