/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    void insertCopies(Node* head)
    {
        Node* temp = head;
        while(temp)
        {
            Node* copy = new Node(temp->val);
            Node* nextElement = temp->next;
            temp->next = copy;
            copy->next = nextElement;
            temp = nextElement;
        }
    }
    void connectRandomPointers(Node* head)
    {
        Node* temp = head;
        while(temp)
        {
            Node* copy = temp->next;
            if(temp->random)
            {
                copy->random = temp->random->next;
            }
            else
            {
                copy->random = NULL;
            }
            temp = temp->next->next;
        }
    }

    Node* getList(Node* head)
    {
        Node* temp = head;
        Node* dummy = new Node(-1);
        Node* res = dummy;
        while(temp)
        {
            res->next = temp->next;
            res = res->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }

        return dummy->next;
    }
    Node* copyRandomList(Node* head) {
        
        insertCopies(head);
        connectRandomPointers(head);
        return getList(head);

    }
};