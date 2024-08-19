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
    int getLength(ListNode* head)
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int lenA = getLength(headA);
        int lenB = getLength(headB);

        while(lenA > lenB)
        {
            lenA--;
            headA = headA->next;
        }
        while(lenB > lenA)
        {
            lenB--;
            headB = headB->next;
        }

        while(headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};