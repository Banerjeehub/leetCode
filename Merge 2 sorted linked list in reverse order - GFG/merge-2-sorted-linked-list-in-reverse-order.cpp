//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}

struct Node * mergeResult(struct Node *node1,struct Node *node2);

Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }

        struct Node* result = mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends


/*

The structure of linked list is the following

struct Node
{
int data;
Node* next;
};

*/
struct Node* reverse(Node* head)
{
    if(!head->next) return head;
    
        Node* newHead = reverse(head->next);
        
        Node* headNext = head->next;
        headNext->next = head;
        head->next = NULL;
        return newHead;
    
}
struct Node * mergeResult(Node *node1,Node *node2)
{
    struct Node* dummy = newNode(1);
    Node* temp = dummy;
    
    while(node1 && node2)
    {
        if(node1->data < node2->data)
        {
            Node* newData = newNode(node1->data);
            dummy->next = newData;
            dummy = dummy->next;
            node1 = node1->next;
        }
        else
        {
            Node* newData = newNode(node2->data);
            dummy->next = newData;
            dummy = dummy->next;
            node2 = node2->next;
        }
    }
    while(node1)
    {
        Node* newData = newNode(node1->data);
        dummy->next = newData;
        dummy = dummy->next;
        node1 = node1->next;
    }
    while(node2)
    {
        Node* newData = newNode(node2->data);
        dummy->next = newData;
        dummy = dummy->next;
        node2 = node2->next;
    }
    
    temp = reverse(temp->next);
    return temp;
    
}