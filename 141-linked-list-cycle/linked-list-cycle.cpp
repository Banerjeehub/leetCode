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
    bool hasCycle(ListNode *head) {
        
        unordered_map<ListNode*, bool>mpp;
        ListNode* temp = head;
        while(temp)
        {
            if(mpp[temp]) return true;
            mpp[temp] = true;
            temp = temp->next;
        }

        return false;
    }
};