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
    ListNode* f(ListNode* fast, ListNode* head)
    {
        ListNode* temp = head;
        while(temp != fast)
        {
            temp = temp->next;
            fast = fast->next;
        }

        return temp;
    }
    ListNode *detectCycle(ListNode *head) {
       
       ListNode* slow = head;
       ListNode* fast = head;

       while(fast && fast->next)
       {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast) return f(fast, head);
       }

       return nullptr;

    }
};