//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


// } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    private:
    void insert(Node* &head, Node* &tail, int data)
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
    Node* reverseBetween(Node* head, int m, int n)
    {
        vector<int>v;
        
        Node* temp = head;
        
        while(temp)
        {
            v.push_back(temp->data);
            temp = temp->next;
        }
        
        reverse(v.begin()+m-1, v.begin()+n);
        
        Node* head1 = NULL;
        Node* tail1 = NULL;
        
        int i=0;
        while(v.size() > i)
        {
            insert(head1, tail1, v[i++]);
            
        }
        
        return head1;
        
        
        
    }
};

//{ Driver Code Starts.

/* Function to print linked list */
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
}



// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}

// } Driver Code Ends