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
    void rev(ListNode* &head, ListNode* curr, ListNode* prev)
    {
        if(curr == nullptr)
        {
            head = prev;
            return;
        }

        ListNode* forw = curr -> next;
        curr->next = prev;
        
        rev(head, forw, curr);
    }
    ListNode* reverseList(ListNode* head) {
        
        rev(head, head, nullptr);
        return head;
        
    }    
};