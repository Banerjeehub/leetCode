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
    int getSize(ListNode* head)
    {
        int count = 0;
        ListNode* temp = head;
        while(temp)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* reverse(ListNode* head, int k, bool flag, int size)
    {
        if(size < k) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forw = NULL;

        for(int i=0; i<k; i++)
        {
            if(curr == NULL)
            {
                flag = 0;
                break;
            }
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }

        if(!flag) return prev;
        head->next = reverse(curr, k, 1, size-k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        int size = getSize(head);
        return reverse(head, k, 1, size);
    }
};