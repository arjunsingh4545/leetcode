/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root; // If the tree is empty, return null

        queue<Node*> q; // Create a queue for BFS
        q.push(root); // Start with the root node

        while (!q.empty()) {
            int size = q.size(); // Get the number of nodes at the current level

            for (int i = 0; i < size; ++i) {
                Node* node = q.front();
                q.pop();

                // Connect the current node to the next node in the queue
                if (i < size - 1) {
                    node->next = q.front(); // Point to the next node in the queue
                }

                // Add child nodes to the queue
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
        }

        return root; 
    }
};