class Solution {
private:
    void insertAtTail(Node* &head, Node* &tail, int data)
    {
        if(!head)
        {
            Node* temp = new Node(data);
            head = temp;
            tail = temp;
            return;
        }

        Node* temp = new Node(data);
        tail->next = temp;
        tail = temp;
    }

public:
    Node* copyRandomList(Node* head) {
        
        Node* newHead = NULL;
        Node* newTail = NULL;

        Node* temp = head;


        //making the deep copy of the existing linkd list through traversing

        while(temp)
        {
            insertAtTail(newHead, newTail, temp->val);
            temp = temp->next;
        }

        unordered_map<Node*, Node*>list;
        Node* oHead = head;
        Node* nHead = newHead;


        //mapping the new Nodes with the old ones

        while(oHead)
        {
            list[oHead] =  nHead;
            nHead = nHead->next;
            oHead = oHead->next;
        }

        //assigning the random pointers to the new nodes

        oHead = head;
        nHead = newHead;

        while(oHead)
        {
            nHead->random = list[oHead->random];
            nHead = nHead->next;
            oHead = oHead->next;
        }

        return newHead;
    }
};