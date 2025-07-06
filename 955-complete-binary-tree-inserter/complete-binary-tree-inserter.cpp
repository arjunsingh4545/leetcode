/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class CBTInserter {
    TreeNode* root;
    queue<TreeNode*> incompleteNodes; // nodes with less than 2 children
public:
    CBTInserter(TreeNode* root) {
        this->root = root;
        queue<TreeNode*> temp;
        temp.push(root);

        // Level-order traversal to find all incomplete nodes
        while (!temp.empty()) {
            TreeNode* node = temp.front();
            temp.pop();

            if (!(node->left && node->right)) {
                incompleteNodes.push(node); // Node has less than 2 children
            }

            if (node->left) temp.push(node->left);
            if (node->right) temp.push(node->right);
        }
    }
    
    int insert(int val) {
        TreeNode* parent = incompleteNodes.front();
        TreeNode* newNode = new TreeNode(val);

        if (!parent->left) {
            parent->left = newNode;
        } else {
            parent->right = newNode;
            incompleteNodes.pop(); // Parent is now complete
        }
        incompleteNodes.push(newNode);
        return parent->val;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */