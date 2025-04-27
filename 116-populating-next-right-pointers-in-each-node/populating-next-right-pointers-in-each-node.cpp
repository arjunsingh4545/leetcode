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

        Node* current = root; // Start with the root node

        while (current->left) { // Traverse levels
            Node* temp = current; // Use a temporary pointer to traverse the current level

            while (temp) { // Traverse nodes in the current level
                // Connect the left child to the right child
                temp->left->next = temp->right;

                // Connect the right child to the next node's left child, if it exists
                if (temp->next) {
                    temp->right->next = temp->next->left;
                }

                // Move to the next node in the current level
                temp = temp->next;
            }

            // Move to the next level
            current = current->left;
        }

        return root; 
    }
};