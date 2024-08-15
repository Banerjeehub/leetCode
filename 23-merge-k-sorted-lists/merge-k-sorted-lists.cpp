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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while (list1 && list2) {
            if (list1->val < list2->val) {
                temp->next = list1;
                temp = temp->next;
                list1 = list1->next;
            } else {
                temp->next = list2;
                temp = temp->next;
                list2 = list2->next;
            }
        }
        if (list1) {
            temp->next = list1;
        }
        if (list2) {
            temp->next = list2;
        }

        return dummy->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
       if (lists.empty()) return nullptr;  
       if (lists.size() == 1) return lists[0];
        
        ListNode* newNode = mergeTwoLists(lists[0], lists[1]);

        for(int i=2; i<lists.size(); i++)
        {
            newNode = mergeTwoLists(newNode, lists[i]);
        }

        return newNode;
    }
};