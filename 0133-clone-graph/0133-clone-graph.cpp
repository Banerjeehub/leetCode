/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        map<Node*, Node*>visited;
        queue<Node*>q;
        q.push(node);
        visited[node] = new Node(node->val);

        while(!q.empty())
        {
            Node* original = q.front();
            q.pop();

            for(auto neighbor : original->neighbors)
            {
                if(!visited.count(neighbor))
                {
                    visited[neighbor] = new Node(neighbor->val);
                    q.push(neighbor);
                }
                visited[original]->neighbors.push_back(visited[neighbor]);

            }
        }

        return visited[node];
    }
};