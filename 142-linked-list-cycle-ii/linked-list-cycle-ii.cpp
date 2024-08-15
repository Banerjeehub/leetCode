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
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*, bool>mpp;
        ListNode* temp = head;
        while(temp)
        {
            if(mpp[temp]) return temp;
            mpp[temp] = true;

            temp = temp->next;
        }

        return nullptr;
    }
};