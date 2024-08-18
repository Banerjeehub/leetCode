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
private:
    int getSize(ListNode* head) {
        ListNode* temp = head;
        int count = 0;

        while (temp) {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode* doTheJob(ListNode* head, int k, int flag, int size) {
        if (size < k)
            return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forw = NULL;

        for (int i = 0; i < k; i++) {
            if (curr == NULL) {
                flag = 0;
                break;
            }

            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
        }

        if (!flag)
            return prev;

        head->next = doTheJob(curr, k, flag, size - k);
        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = getSize(head);
        head = doTheJob(head, k, 1, size);
        return head;
    }
};