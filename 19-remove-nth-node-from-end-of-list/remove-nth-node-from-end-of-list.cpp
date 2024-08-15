/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reverse(ListNode* &head, ListNode* curr, ListNode* prev)
    {
        if(!curr)
        {
            head = prev;
            return;
        }

        ListNode* forw = curr->next;
        curr->next = prev;
        reverse(head, forw, curr);
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        reverse(head, head, nullptr);
        if(n == 1)
        {
            head = head->next;
            reverse(head, head, nullptr);
            return head;
        }
        int count = 1;
        ListNode* temp = head;
        ListNode* prev = NULL;
        while(count < n)
        {
            prev = temp;
            temp = temp->next;
            count++;
        }

        prev->next = temp->next;
        temp->next = NULL;

        reverse(head, head, nullptr);
        return head;

    }
};