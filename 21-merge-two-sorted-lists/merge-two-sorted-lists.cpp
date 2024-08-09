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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         if (!l1) return l2;
        if (!l2) return l1;
        
        // Make sure that l1 is always the smaller node to start with
        if (l1->val > l2->val) std::swap(l1, l2);

        ListNode* head = l1;  // l1 is the head of the merged list
        
        while (l1 != nullptr && l2 != nullptr) {
            ListNode* temp = nullptr;

            // Traverse through nodes in l1 as long as they are smaller than l2
            while (l1 != nullptr && l1->val <= l2->val) {
                temp = l1;  // Keep track of the last node
                l1 = l1->next;  // Move l1 to the next node
            }

            // Attach the smaller node (from l2) to the last node processed in l1
            temp->next = l2;

            // Swap l1 and l2 so that the smaller node is again in l1
            std::swap(l1, l2);
        }

        return head;
    }
};