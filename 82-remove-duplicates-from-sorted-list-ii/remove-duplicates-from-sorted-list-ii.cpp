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
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr)
        {
            bool isDup = false;
            while(curr->next && curr->val == curr->next->val)
            {
                curr = curr->next;
                isDup = true;
            }
            if(isDup)
            {
                if(prev)
                {
                    prev->next = curr->next;
                }
                else
                {
                    head = curr->next;
                }
            }
            else
            {
                prev = curr;
            }

            curr = curr->next;
        }

        return head;
    }
};