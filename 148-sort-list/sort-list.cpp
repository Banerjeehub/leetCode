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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* temp = new ListNode(-1);

        ListNode* head = temp;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                head->next = list1;
                head = list1;
                list1 = list1->next;
            } else {
                head->next = list2;
                head = list2;
                list2 = list2->next;
            }
        }

        if (list1) {
            head->next = list1;
        }
        if (list2) {
            head->next = list2;
        }

        return temp->next;
    }
    ListNode* middle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
    ListNode* sortList(ListNode* head) {

        if (!head || !head->next)
            return head;

        ListNode* mid = middle(head);
        ListNode* left = head;
        ListNode* right = mid->next;
        mid->next = NULL;

        left = sortList(left);
        right = sortList(right);

        return merge(left, right);
    }
};