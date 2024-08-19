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
    ListNode* reverseList(ListNode* head) {
        
        ListNode* prev = nullptr;
        ListNode* curr = head;
        reverse(head, curr, prev);
        return head;
    }
};